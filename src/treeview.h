#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <vector>
#include <string>
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
#include "document.h"
#include "utils.h"
#include "projectdefinitions.h"

class MainWindow : public Gtk::ApplicationWindow {
public:
    MainWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder);

    virtual ~MainWindow();

    static MainWindow *create();

    void serialize_json_by_filename(const std::string&);
    rapidjson::Document* jsonDocument;
private:
    std::string jsonFileName;
    Glib::RefPtr<Gtk::Builder> builder;
    Glib::RefPtr<Gio::Settings> settings;
    Gtk::HeaderBar *headerBar;
    void setHeaderBar();
    // rapidjson::Value get_model_child(rapidjson::Value&);
    std::vector<const char*> typeNames;

protected:
    Gtk::ScrolledWindow scrolledWindow;
    Glib::RefPtr<Gtk::TreeView> treeView;
    Glib::RefPtr<Gtk::TreeStore> treeStore;
    Gtk::TreeModelColumnRecord* columnRecord;
};

#endif  // WINDOW_H