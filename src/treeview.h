#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <vector>
#include <giomm/settings.h>
#include <gtkmm/applicationwindow.h>
#include <gtkmm/builder.h>
#include <gtkmm/box.h>
#include <gtkmm/headerbar.h>
#include <gtkmm/label.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/treemodelcolumn.h>
#include <gtkmm/treestore.h>
#include <gtkmm/treeview.h>
#include <gtkmm/settings.h>
#include <gtkmm/scrolledwindow.h>
#include "rapidjson/document.h"
#include "projectdefinitions.h"

class TreeViewWindow : public Gtk::ApplicationWindow {
public:
    TreeViewWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder);

    virtual ~TreeViewWindow();

    static TreeViewWindow *create();
    Gtk::TreeModel generateModel();

    void load_tree_view(rapidjson::Document&);
    rapidjson::Document* document;

private:
    Glib::RefPtr<Gtk::Builder> builder;
    Glib::RefPtr<Gio::Settings> settings;
    Gtk::HeaderBar *headerBar;

    void setHeaderBar();
    rapidjson::Value get_model_child(rapidjson::Value&);
    std::vector<const char*> typeNames;

protected:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::TreeView treeView;
    Glib::RefPtr<Gtk::TreeStore> treeModel;
};

#endif  // WINDOW_H