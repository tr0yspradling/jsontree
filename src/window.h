#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <giomm/settings.h>
#include <gtkmm/applicationwindow.h>
#include <gtkmm/builder.h>
#include <gtkmm/box.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/label.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/treestore.h>
#include <gtkmm/treeview.h>
#include <gtkmm/settings.h>
#include <gtkmm/scrolledwindow.h>
#include "rapidjson/document.h"
#include "projectdefinitions.h"

class Window : public Gtk::ApplicationWindow {
public:
    Window(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder);

    virtual ~Window();

    static Window *create();
    void load_tree_view(rapidjson::Document&);

private:
    Glib::RefPtr<Gtk::Builder> builder;
    Glib::RefPtr<Gio::Settings> settings;
    Gtk::HeaderBar *headerBar;

    void setHeaderBar();

protected:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::TreeView treeView;
    Glib::RefPtr<Gtk::TreeStore> treeModel;
};

#endif  // WINDOW_H