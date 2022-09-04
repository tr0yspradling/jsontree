#include <iostream>
#include "application.h"
#include "projectdefinitions.h"
#include "utils.h"

Application::Application() : Gtk::Application(projectdefinitions::getApplicationID() + ".application") {}

Application::~Application() {}

Glib::RefPtr<Application> Application::create() {
    return Glib::RefPtr<Application>(new Application());
}

TreeViewWindow *Application::createWindow() {
    auto window = TreeViewWindow::create();
    add_window(*window);
    window->signal_hide().connect(sigc::bind(sigc::mem_fun(*this, &Application::on_hide_window), window));
    return window;
}

void Application::on_activate() {
    try {
        auto window = createWindow();
        window->present();
    } catch (const Glib::Error &ex) {
        std::cerr << "Application::on_activate(): " << ex.what() << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "Application::on_activate(): " << ex.what() << std::endl;
    }
}

void Application::on_startup() {
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

    auto object = builder->get_object("appmenu");
    auto app_menu = Glib::RefPtr<Gio::MenuModel>::cast_dynamic(object);
    if (app_menu) {
        set_app_menu(app_menu);
    } else {
        std::cerr << "Application::on_startup(): No \"appmenu\" object in menu.glade" << std::endl;
    }
}

void Application::on_hide_window(Gtk::Window *window) {
    delete window;
}

void Application::on_action_open_file() {
    Gtk::FileChooserDialog dialog("Please choose a file",
                                  Gtk::FILE_CHOOSER_ACTION_OPEN);

    dialog.set_transient_for(*this->get_active_window());

    // Add response buttons to the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    // Add filters, so that only certain file types can be selected:
    auto filter_json = Gtk::FileFilter::create();
    filter_json->set_name("JSON files");
    filter_json->add_mime_type("application/json");
    dialog.add_filter(filter_json);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    // Show the dialog and wait for a user response:
    int result = dialog.run();

    std::string filename;

    // Handle the response:
    switch (result) {
        case (Gtk::RESPONSE_OK): {
            // Notice that this is a std::string, not a Glib::ustring.
            filename = dialog.get_filename();
            std::cout << "" << std::endl;
            break;
        }
        case (Gtk::RESPONSE_CANCEL): {
            break;
        }
        default: {
            break;
        }
    }
    // auto window = (TreeViewWindow*) get_active_window();
    // window->serialize_json_by_filename(filename);
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
