#include "treeview.h"

TreeViewWindow::TreeViewWindow(Gtk::ApplicationWindow::BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder)
        : Gtk::ApplicationWindow(cobject),
          builder(builder),
          settings(nullptr),
          headerBar(nullptr),
          treeView() {
    set_icon(Gdk::Pixbuf::create_from_resource(projectdefinitions::getApplicationPrefix() + "icons/64x64/icon.png"));
    setHeaderBar();

    // if value is object or array, create parent/child nodes
    // otherwise create text node for key/value
    typeNames = {
            "Null", "False", "True", "Object", "Array", "String", "Number"
    };
}

TreeViewWindow::~TreeViewWindow() {
    delete document;
}

TreeViewWindow *TreeViewWindow::create() {
    auto builder = Gtk::Builder::create_from_resource(projectdefinitions::getApplicationPrefix() + "ui/window.glade");

    TreeViewWindow *window = nullptr;
    builder->get_widget_derived("window", window);
    if (!window) {
        throw std::runtime_error("No \"window\" object in window.glade");
    }
    return window;
}

void TreeViewWindow::setHeaderBar() {
    auto builder =
            Gtk::Builder::create_from_resource(projectdefinitions::getApplicationPrefix() + "ui/headerbar.glade");
    builder->get_widget("headerBar", headerBar);
    if (!headerBar) {
        throw std::runtime_error("No \"headerBar\" object in headerbar.glade");
    } else {
        headerBar->set_title(projectdefinitions::getProjectName());
        set_titlebar(*headerBar);
    }
}

Gtk::TreeModel TreeViewWindow::generateModel() {
    for (auto& m : document->GetObject()) {
        std::string key = m.name.GetString();
        std::string type = typeNames[m.value.GetType()];
        printf("Type of member %s is %s\n", m.name.GetString(), type.c_str());
    }
}

rapidjson::Value TreeViewWindow::get_model_child(rapidjson::Value &node) {

}

void TreeViewWindow::load_tree_view(rapidjson::Document &data) {
    document = &data;
    // generateModel();
    Gtk::TreeModel _model = generateModel();
}
