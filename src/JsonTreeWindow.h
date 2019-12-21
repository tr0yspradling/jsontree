//
// Created by troy on 12/21/19.
//

#ifndef JSONTREE_JSONTREEWINDOW_H
#define JSONTREE_JSONTREEWINDOW_H

#include <gtkmm.h>
#include "OpenFileWindow.hpp"

class JsonTreeWindow : public Gtk::Window {
public:
    JsonTreeWindow();

    virtual ~JsonTreeWindow();

protected:
    //Signal handlers:
    void on_button_quit();

    void on_button_load_file();

    void on_treeview_row_activated(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *column);

    //Tree model columns:
    class ModelColumns : public Gtk::TreeModel::ColumnRecord {
    public:

        ModelColumns() {
            add(m_col_id);
            add(m_col_name);
        }

        Gtk::TreeModelColumn<int> m_col_id;
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    };

    ModelColumns m_Columns;

    //Child widgets:
    Gtk::Box m_VBox;

    Gtk::ScrolledWindow m_ScrolledWindow;
    Gtk::TreeView m_TreeView;
    Glib::RefPtr<Gtk::TreeStore> m_refTreeModel;

    Gtk::ButtonBox m_ButtonBox;
    Gtk::Button m_Button_Quit;
    Gtk::Button m_Button_Open_File;

    OpenFileWindow openFileWindow;
};

#endif //JSONTREE_JSONTREEWINDOW_H
