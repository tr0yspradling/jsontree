#include "treewindow.h"

TreeWindow::TreeWindow(
  Gtk::ApplicationWindow::BaseObjectType *cobject,
  const Glib::RefPtr<Gtk::Builder> &builder
) : Gtk::ApplicationWindow(cobject) {
  set_icon_name(projectdefinitions::getApplicationPrefix() + "icons/64x64/icon.png");

  view_stack = Glib::make_refptr_for_instance(builder->get_widget<Gtk::Stack>("stack"));
  if (!view_stack)
    throw std::runtime_error("No 'stack' object in main.glade.");

  gears = Glib::make_refptr_for_instance(builder->get_widget<Gtk::MenuButton>("gears"));
  if (!gears)
    throw std::runtime_error("No 'gears' object in main.glade.");

  auto menu_builder = Gtk::Builder::create_from_resource(
    projectdefinitions::getApplicationPrefix() + "ui/menu.glade"
  );
  auto menu = menu_builder->get_object<Gio::MenuModel>("appmenu");
  if (!menu)
    throw std::runtime_error("No \"menu\" object in menu.ui");

  gears->set_menu_model(menu);
}

TreeWindow::~TreeWindow() {
  g_free(contents);
  // delete json_document;
}

TreeWindow *TreeWindow::create() {
  auto builder = Gtk::Builder::create_from_resource(
    projectdefinitions::getApplicationPrefix() + "ui/main.glade"
  );
  auto window = Gtk::Builder::get_widget_derived<TreeWindow>(builder, "window");
  if (!window) {
    throw std::runtime_error("No \"window\" object in main.glade");
  }
  return window;
}

void TreeWindow::on_row_selected() {
  auto iter = tree_selection->get_selected();
  if(iter) {
    auto row = *iter;
    // get the data from the selected row
    std::cout << row.get_value(tree_columns.key) << ": " << row.get_value(tree_columns.value) << std::endl;
  }
}

void TreeWindow::on_json_file_read(const Glib::RefPtr<Gio::AsyncResult>& result) {
  file->load_contents_finish(result, contents, length);
  try {
    load_tree_view();
  } catch (const Glib::Error &ex) {
    std::cout << "TreeWindow::open_file_view(\"" << file->get_parse_name() << "\"):\n  " << ex.what() << std::endl;
  }
}

void TreeWindow::open_file_view(const std::shared_ptr<Gio::File>& _file) {
  file = _file;
  try {
    file->load_contents_async(
      sigc::mem_fun(*this, &TreeWindow::on_json_file_read)
    );
  } catch (const Glib::Error &ex) {
    std::cout << "TreeWindow::open_file_view(\"" << file->get_parse_name() << "\"):\n  " << ex.what() << std::endl;
  }

  json_file_basename = file->get_basename();
  json_file_path = file->get_path();

  scrolled_window = std::make_shared<Gtk::ScrolledWindow>();
  scrolled_window->set_policy(
    Gtk::PolicyType::AUTOMATIC,
    Gtk::PolicyType::AUTOMATIC
  );
  tree_view = std::make_shared<Gtk::TreeView>();
  tree_selection = tree_view->get_selection();
  tree_selection->signal_changed().connect(
    sigc::mem_fun(*this, &TreeWindow::on_row_selected)
  );

  scrolled_window->set_child(*tree_view);
  scrolled_window->set_expand(true);

  view_stack->add(*scrolled_window, json_file_basename, json_file_basename);
  view_stack->set_visible_child(*scrolled_window);

  tree_store = Gtk::TreeStore::create(tree_columns);
  tree_view->set_model(tree_store);
  tree_view->set_reorderable(true);
}

void TreeWindow::load_tree_view() {
  json_document = std::make_shared<rapidjson::Document>();
  json_document->Parse(contents);

//  while(!json_document->Empty()) {
//    if (json_document->IsObject()) {
//      auto tree_row = *(tree_store->append());
//      tree_row[tree_columns.value] = "{}";
//
//
//    } else if (json_document->IsArray()) {
//
//    } else {
//      set_row_value(*(tree_store->append()), *json_document);
//    }
//  }

  if (json_document->IsObject()) {
    for (auto it = json_document->MemberBegin(); it != json_document->MemberEnd(); ++it) {
      parse_value(it->name.GetString(), *(tree_store->append()), it->value);
    }
  } else if (json_document->IsArray()) {
    for (auto it = json_document->Begin(); it != json_document->End(); ++it) {
      std::size_t index = it - json_document->Begin();
      std::string scope_repr = "[" + std::to_string(index) + "]";
      parse_value(scope_repr, *(tree_store->append()), *it);
    }
  } else {
    set_row_value(*(tree_store->append()), *json_document);
  }
  //Add the TreeView's view columns:
  tree_view->append_column("key", tree_columns.key);
  tree_view->append_column("value", tree_columns.value);
}

/* Fill the Tree's model */
void TreeWindow::parse_value(
  std::string scope,
  Gtk::TreeRow row,
  rapidjson::Value &object
) {
  if (object.IsObject()) {
    row[tree_columns.value] = "{}";
    for (auto it = object.MemberBegin(); it != object.MemberEnd(); ++it) {
      parse_value(
        scope + "." + it->name.GetString(),
        *(tree_store->append(row.children())),
        it->value
      );
    }
  } else if (object.IsArray()) {
    row[tree_columns.value] = "[]";
    for (auto it = object.Begin(); it != object.End(); ++it) {
      std::size_t index = it - object.Begin();
      std::string scope_repr = scope + "[" + std::to_string(index) + "]";
      parse_value(
        scope_repr, *(tree_store->append(row.children())), *it
      );
    }
  } else {
    try {
      set_row_value(row, object);
    } catch (std::runtime_error &ex) {
      std::cout << "TreeWindow::parse_object(\"" << &object << "\"):\n  " << ex.what() << std::endl;
    }
  }
  row[tree_columns.key] = Glib::ustring(scope);
}

void TreeWindow::set_row_value(Gtk::TreeRow row, rapidjson::Value &object) const {
  Glib::ustring str_value;
  try {
    if (object.IsString()) {
      str_value = Glib::ustring(object.GetString());
    } else if (object.IsInt()) {
      str_value = Glib::ustring(std::to_string(object.GetInt()));
    } else if (object.IsDouble()) {
      str_value = Glib::ustring(std::to_string(object.GetDouble()));
    } else if (object.IsFloat()) {
      str_value = Glib::ustring(std::to_string(object.GetFloat()));
    } else if (object.IsBool()) {
      str_value = object.GetBool() ? "true" : "false";
    } else if (object.IsNull()) {
      str_value = Glib::ustring("null");
    }
    row[tree_columns.value] = str_value;
  } catch (std::runtime_error &ex) {
    std::cout << "TreeWindow::set_row_value(\"" << str_value << "\"):\n  " << ex.what() << std::endl;
  }
}
