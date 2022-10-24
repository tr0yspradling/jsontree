#include <iostream>
#include "application.h"
#include "projectdefinitions.h"
#include "utils.h"

Application::Application()
: Gtk::Application(projectdefinitions::getApplicationID() + ".application",
                   Gio::Application::Flags::HANDLES_OPEN)
{
    Glib::set_application_name(Glib::ustring("JSONTree"));
}

Application::~Application() {}

Glib::RefPtr<Application> Application::create() {
    return Glib::make_refptr_for_instance<Application>(new Application());
}

TreeWindow* Application::create_window() {
    auto window = TreeWindow::create();
    add_window(*window);
    window->signal_hide().connect(
        sigc::bind(sigc::mem_fun(*this, &Application::on_hide_window), window)
    );
    window->set_show_menubar();
    return window;
}

void Application::on_activate() {
    try {
        auto window = create_window();
        window->present();
    } catch (const Glib::Error &ex) {
        std::cerr << "Application::on_activate(): " << ex.what() << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "Application::on_activate(): " << ex.what() << std::endl;
    }
}

void Application::on_open(const Gio::Application::type_vec_files& files, const Glib::ustring& hint)
{
    // The application has been asked to open some files,
    // so let's open a new view for each one.
    TreeWindow* tree_window = nullptr;
    auto windows = get_windows();
    if (!windows.empty())
        tree_window = dynamic_cast<TreeWindow*>(windows[0]);

    try {
        if (!tree_window)
            tree_window = create_window();

        for (const auto &file: files)
            tree_window->open_file_view(file);

        tree_window->present();
    } catch (const Glib::Error& ex) {
        std::cerr << "TreeWindow::on_open: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "TreeWindow::on_open: " << ex.what() << std::endl;
    }
}


void Application::on_startup() {
    // call base class's implementation
    Gtk::Application::on_startup();
    add_action("open_file", sigc::mem_fun(*this, &Application::on_action_open_file));
    add_action("preferences", sigc::mem_fun(*this, &Application::on_action_preferences));
    add_action("quit", sigc::mem_fun(*this, &Application::on_action_quit));
    set_accel_for_action("app.quit", "<Ctrl>Q");

    auto builder = Gtk::Builder::create();
    try {
        builder->add_from_resource(projectdefinitions::getApplicationPrefix() + "ui/menu.glade");
    } catch (const Glib::Error &ex) {
        std::cerr << "Application::on_startup(): " << ex.what() << std::endl;
        return;
    }
    auto app_menu = builder->get_object<Gio::Menu>("appmenu");
    if (!app_menu) {
        std::cerr << "Application::on_startup(): No \"appmenu\" object in menu.glade" << std::endl;
        return;
    }

    set_menubar(app_menu);
}

void Application::on_hide_window(Gtk::Window *window) {
    delete window;
}

void Application::on_action_open_file() {
    auto dialog = new Gtk::FileChooserDialog("Please choose a file",
                                             Gtk::FileChooser::Action::OPEN);

    dialog->set_transient_for(*this->get_active_window());
    dialog->set_modal(true);
    dialog->signal_response().connect(
        sigc::bind(sigc::mem_fun(*this, &Application::on_file_dialog_response), dialog)
    );

    // Add response buttons to the dialog:
    dialog->add_button("_Cancel", Gtk::ResponseType_Wrapper::CANCEL);
    dialog->add_button("_Open", Gtk::ResponseType_Wrapper::OK);

    // Add filters, so that only certain file types can be selected:
    auto filter_json = Gtk::FileFilter::create();
    filter_json->set_name("JSON files");
    filter_json->add_mime_type("application/json");
    dialog->add_filter(filter_json);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog->add_filter(filter_any);

    dialog->show();
}

void Application::on_file_dialog_response(int response_id, Gtk::FileChooserDialog* dialog)
{
    //Handle the response:
    switch (response_id)
    {
        case Gtk::ResponseType::OK:
        {
            std::cout << "Open clicked." << std::endl;
            //Notice that this is a std::string, not a Glib::ustring.
            auto filename = dialog->get_file()->get_path();
            std::cout << "File selected: " << filename << std::endl;
            auto file_for_path = Gio::File::create_for_path(filename);
            on_open(std::vector<std::shared_ptr<Gio::File>>{file_for_path}, filename);
            break;
        }
        case Gtk::ResponseType::CANCEL:
        {
            std::cout << "Cancel clicked." << std::endl;
            break;
        }
        default:
        {
            std::cout << "Unexpected button clicked." << std::endl;
            break;
        }
    }
    delete dialog;
}

void Application::on_action_preferences() {
    try {
        auto prefsDialog = Preferences::create(*get_active_window());
        prefsDialog->present();
        prefsDialog->signal_hide().connect(sigc::bind(sigc::mem_fun(*this, &Application::on_hide_window), prefsDialog));
    } catch (const Glib::Error &ex) {
        std::cerr << "Application::on_action_preferences(): " << ex.what() << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "Application::on_action_preferences(): " << ex.what() << std::endl;
    }
}
void Application::on_action_quit() {
    auto windows = get_windows();
    for (auto window : windows) {
        window->hide();
    }
    quit();
}
