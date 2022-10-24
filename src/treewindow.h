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
#include <gtkmm/stack.h>
#include <gtkmm/menubutton.h>
#include "document.h"
#include "utils.h"
#include "projectdefinitions.h"

class TreeWindow : public Gtk::ApplicationWindow {
public:
    TreeWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder);

    virtual ~TreeWindow();

    static TreeWindow *create();

    void open_file_view(const Glib::RefPtr<Gio::File> &);

    // Loads the `tree_view` from a char* containing JSON
    void load_tree_view(char* &);

    void parse_object(std::string scope,
                      Gtk::TreeRow row,
                      rapidjson::Value::ConstMemberIterator object);
    void parse_array(std::string scope,
                      Gtk::TreeRow row,
                      rapidjson::Value::ConstValueIterator object);
    Glib::ustring json_file_name;
protected:
    std::vector<const char*> json_type_names;
    rapidjson::Document* json_document {nullptr};
    char* contents {nullptr};
    gsize length {0};
    std::shared_ptr<Gio::File> file;

    std::shared_ptr<Gtk::Builder> builder;
    std::shared_ptr<Gio::Settings> settings {nullptr};
    Gtk::MenuButton* gears {nullptr};
    // Gtk::HeaderBar* header_bar {nullptr};
    Gtk::Stack* view_stack {nullptr};
    std::shared_ptr<Gtk::ScrolledWindow> scrolled_window {nullptr};
    std::shared_ptr<Gtk::TreeView> tree_view {nullptr};
    std::shared_ptr<Gtk::TreeStore> tree_store {nullptr};
    std::shared_ptr<Gtk::TreeModelColumnRecord> tree_column_record {nullptr};
    class TreeModelColumns : public Gtk::TreeModel::ColumnRecord
    {
    public:
        TreeModelColumns() { add(key); add(value); }
        Gtk::TreeModelColumn<Glib::ustring> key;
        Gtk::TreeModelColumn<Glib::ustring> value;
    };
    TreeModelColumns tree_columns;

};

#endif  // WINDOW_H