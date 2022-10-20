#include "treeview.h"

MainWindow::MainWindow(Gtk::ApplicationWindow::BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder)
        : Gtk::ApplicationWindow(cobject),
          builder(builder),
          settings(nullptr),
          headerBar(nullptr),
          treeView(nullptr),
          treeStore(nullptr) {
    set_icon_name(projectdefinitions::getApplicationPrefix() + "icons/64x64/icon.png");
    setHeaderBar();

    // if value is object or array, create parent/child nodes
    // otherwise create text node for key/value
    typeNames = {
            "Null", "False", "True", "Object", "Array", "String", "Number"
    };
}

MainWindow::~MainWindow() {
    delete jsonDocument;
}

MainWindow* MainWindow::create() {
    auto builder = Gtk::Builder::create_from_resource(projectdefinitions::getApplicationPrefix() + "ui/main.glade");

    auto window = Gtk::Builder::get_widget_derived<MainWindow>(builder, "window");
    if (!window) {
        throw std::runtime_error("No \"window\" object in main.glade");
    }
    return window;
}

void MainWindow::setHeaderBar() {
    auto builder =
            Gtk::Builder::create_from_resource(projectdefinitions::getApplicationPrefix() + "ui/headerbar.glade");
    headerBar = builder->get_widget<Gtk::HeaderBar>("headerBar");
    if (!headerBar) {
        throw std::runtime_error("No \"headerBar\" object in headerbar.glade");
    } else {
        set_titlebar(*headerBar);
    }
}

void MainWindow::serialize_json_by_filename(const std::string& filename) {
    jsonDocument = new rapidjson::Document ();
    jsonDocument->Parse(read_file(filename).c_str());
    for (auto& _object : jsonDocument->GetObject()) {
        std::string key = _object.name.GetString();
        std::string type = typeNames[_object.value.GetType()];
        printf("Type of member %s is %s\n", _object.name.GetString(), type.c_str());
    }
    columnRecord = new Gtk::TreeModelColumnRecord();
    Gtk::TreeModelColumn<Glib::ustring> *column = new Gtk::TreeModelColumn<Glib::ustring>();
    columnRecord->add(*column);
    treeStore->set_column_types(*columnRecord);
    treeView->set_model(treeStore);
    std::cout << "DONE" << std::endl;
}
