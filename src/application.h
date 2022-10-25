#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm/icontheme.h>
#include <gtkmm/filechooserdialog.h>
#include <glibmm/miscutils.h>
#include "preferences.h"
#include "treewindow.h"

class Application : public Gtk::Application {
public:
    ~Application() override;

    static Glib::RefPtr<Application> create();

private:
    Application();

    TreeWindow *create_window();

    void on_activate() override;

    void on_startup() override;

    void on_hide_window(Gtk::Window *window);

    void on_action_open_file();

    void on_action_preferences();

    void on_action_quit();

    void on_open(const type_vec_files &files, const Glib::ustring &) override;

    void on_file_dialog_response(int, Gtk::FileChooserDialog *);
};

#endif  // APPLICATION_H
