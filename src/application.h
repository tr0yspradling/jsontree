#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm/filechooserdialog.h>
#include "preferences.h"
#include "treeview.h"

class Application : public Gtk::Application {
public:
    ~Application() override;

    static Glib::RefPtr<Application> create();

private:
    Application();

    MainWindow *createWindow();
    
    void on_activate() override;

    void on_startup() override;

    void on_hide_window(Gtk::Window *window);

    void on_action_open_file();

    void on_action_preferences();

    void on_action_quit();

};

#endif  // APPLICATION_H
