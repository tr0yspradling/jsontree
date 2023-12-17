#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <memory>
#include <string>
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
#include <gtkmm/stack.h>
#include <gtkmm/menubutton.h>
#include "document.h"
#include "projectdefinitions.h"

class TreeModelColumns : public Gtk::TreeModel::ColumnRecord {
public:
  TreeModelColumns() {
    add(key);
    add(value);
  }

  Gtk::TreeModelColumn<Glib::ustring> key;
  Gtk::TreeModelColumn<Glib::ustring> value;
};

class TreeWindow : public Gtk::ApplicationWindow {
public:
  TreeWindow(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &builder);

  virtual ~TreeWindow();

  static TreeWindow *create();

  void open_file_view(const std::shared_ptr<Gio::File> &);

  // Loads the `tree_view` from JSON inside TreeWindow::*contents
  void load_tree_view();

  void on_json_file_read(const Glib::RefPtr<Gio::AsyncResult>& result);

  void parse_value(
    std::string scope,
    Gtk::TreeRow row,
    rapidjson::Value &object
  );

  /*
   * This function is called before any node is selected or unselected, giving some control over which nodes are selected.
   * The select function should return true if the state of the node may be toggled, and FALSE if the state of the node should be left unchanged.
   */
  void on_row_selected();

protected:
  void set_row_value(Gtk::TreeRow row, rapidjson::Value &object) const;

  std::string json_file_basename;
  std::string json_file_path;

  std::shared_ptr<rapidjson::Document> json_document{nullptr};
  char* contents{nullptr};

  gsize length{0};
  std::shared_ptr<Gio::File> file{nullptr};

  // std::shared_ptr<Gtk::Builder> builder;
  std::shared_ptr<Gio::Settings> settings{nullptr};
  Glib::RefPtr<Gtk::MenuButton> gears{nullptr};
  Glib::RefPtr<Gtk::Stack> view_stack{nullptr};
  std::shared_ptr<Gtk::ScrolledWindow> scrolled_window{nullptr};
  std::shared_ptr<Gtk::TreeView> tree_view{nullptr};
  std::shared_ptr<Gtk::TreeStore> tree_store{nullptr};
  std::shared_ptr<Gtk::TreeSelection> tree_selection{nullptr};

  TreeModelColumns tree_columns;
};

#endif  // WINDOW_H