#include <gtkmm/textview.h>

#include <memory>
#include "treewindow.h"

TreeWindow::TreeWindow(Gtk::ApplicationWindow::BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder)
        : Gtk::ApplicationWindow(cobject),
          builder(builder) {
    set_icon_name(projectdefinitions::getApplicationPrefix() + "icons/64x64/icon.png");


    view_stack = builder->get_widget<Gtk::Stack>("stack");
    if (!view_stack)
        throw std::runtime_error("No 'stack' object in main.glade.");

    gears = builder->get_widget<Gtk::MenuButton>("gears");
    if (!gears)
        throw std::runtime_error("No 'gears' object in main.glade.");
    auto menu_builder = Gtk::Builder::create_from_resource(
        projectdefinitions::getApplicationPrefix() + "ui/menu.glade"
    );
    auto menu = menu_builder->get_object<Gio::MenuModel>("appmenu");
    if (!menu)
        throw std::runtime_error("No \"menu\" object in menu.ui");

    gears->set_menu_model(menu);
    // if value is object or array, create parent/child nodes
    // otherwise create text node for key/value
    json_type_names = {
            "Null", "False", "True", "Object", "Array", "String", "Number"
    };
}

TreeWindow::~TreeWindow(){
    g_free(contents);
    delete json_document;
}

TreeWindow* TreeWindow::create() {
    auto builder = Gtk::Builder::create_from_resource(
        projectdefinitions::getApplicationPrefix() + "ui/main.glade"
    );
    auto window = Gtk::Builder::get_widget_derived<TreeWindow>(builder, "window");
    if (!window) {
        throw std::runtime_error("No \"window\" object in main.glade");
    }
    return window;
}

void TreeWindow::open_file_view(const Glib::RefPtr<Gio::File>& _file) {
    file = _file;
    const Glib::ustring basename = file->get_basename();
    std::cout << "file->get_basename(): " << file->get_basename() << std::endl;
    std::cout << "file->get_path(): " << file->get_path() << std::endl;

    // auto scrolled = Gtk::make_managed<Gtk::ScrolledWindow>();
    scrolled_window = std::make_shared<Gtk::ScrolledWindow>();
    tree_view = std::make_shared<Gtk::TreeView>();
    scrolled_window->set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
    scrolled_window->set_expand(true);
    scrolled_window->set_child(*tree_view);
    view_stack->add(*scrolled_window, basename, basename);
    view_stack->set_visible_child(*scrolled_window);

    try {
        file->load_contents(contents, length);
    } catch (const Glib::Error& ex) {
        std::cout << "TreeWindow::open_file_view(\"" << file->get_parse_name()
                  << "\"):\n  " << ex.what() << std::endl;
    }

    try{
        load_tree_view(contents);
    } catch (const Glib::Error& ex) {
        std::cout << "TreeWindow::open_file_view(\"" << file->get_parse_name() << "\"):\n  " << ex.what() << std::endl;
    }
}

void TreeWindow::load_tree_view(char* &_contents) {
    json_document = new rapidjson::Document();
    json_document->Parse(_contents);
    tree_store = Gtk::TreeStore::create(tree_columns);
    //Create the Tree model:
    tree_view->set_model(tree_store);
    //All the items to be reordered with drag-and-drop:
    // tree_view->set_reorderable();

    for (auto it = json_document->MemberBegin(); it != json_document->MemberEnd(); ++it) {
        parse_object("", *(tree_store->append()), it);
    }

    //Add the TreeView's view columns:
    tree_view->append_column("key", tree_columns.key);
    tree_view->append_column("value", tree_columns.value);
    std::cout << "DONE" << std::endl;
}

void TreeWindow::parse_object(
    std::string scope,
    Gtk::TreeRow row,
    rapidjson::Value::ConstMemberIterator object) {
    Glib::ustring value = "?";

    //Fill the TreeView's model
    if (scope.empty()) {
        scope = object->name.GetString();
    } else {
        scope = scope + "." + object->name.GetString();
    }

    row[tree_columns.key] = Glib::ustring(scope);

    if (object->value.IsObject()) {
        for (auto it = object->value.MemberBegin(); it != object->value.MemberEnd(); ++it) {
            parse_object(scope, *(tree_store->append(row.children())), it);
        }
        value = "{}";
    } else if (object->value.IsArray()) {
        for (auto it = object->value.Begin(); it != object->value.End(); ++it) {
            parse_array("", *(tree_store->append(row.children())), it);
        }
        value = "[]";
    } else if (object->value.IsString()) {
        try {
            value = Glib::ustring(object->value.GetString());
        } catch (std::runtime_error &ex) {
            std::cout << ex.what() << std::endl;
        }
    } else if (object->value.IsInt()) {
        value = Glib::ustring(std::to_string(object->value.GetInt()));
    } else if (object->value.IsDouble()) {
        value = Glib::ustring(std::to_string(object->value.GetDouble()));
    } else if (object->value.IsFloat()) {
        value = Glib::ustring(std::to_string(object->value.GetFloat()));
    } else if (object->value.IsBool()) {
        value = object->value.GetBool() ? "true" : "false";
    } else if (object->value.IsNull()) {
        value = Glib::ustring("null");
    }
    row[tree_columns.value] = value;
}

void TreeWindow::parse_array(
        std::string scope,
        Gtk::TreeRow row,
        rapidjson::Value::ConstValueIterator object) {
    Glib::ustring value = "[]";
    row[tree_columns.key] = Glib::ustring(scope);
    if (object->IsObject()) {
        for (auto it = object->MemberBegin(); it != object->MemberEnd(); ++it) {
            parse_object(scope, *(tree_store->append(row.children())), it);
        }
        value = "{}";
    } else if (object->IsArray()) {
        for (auto it = object->Begin(); it != object->End(); ++it) {
            parse_array("", *(tree_store->append(row.children())), it);
        }
        value = "[]";
    } else if (object->IsString()) {
        try {
            value = Glib::ustring(object->GetString());
        } catch (std::runtime_error &ex) {
            std::cout << ex.what() << std::endl;
        }
    } else if (object->IsInt()) {
        value = Glib::ustring(std::to_string(object->GetInt()));
    } else if (object->IsDouble()) {
        value = Glib::ustring(std::to_string(object->GetDouble()));
    } else if (object->IsFloat()) {
        value = Glib::ustring(std::to_string(object->GetFloat()));
    } else if (object->IsBool()) {
        value = object->GetBool() ? "true" : "false";
    } else if (object->IsNull()) {
        value = Glib::ustring("null");
    }
    row[tree_columns.value] = value;
}