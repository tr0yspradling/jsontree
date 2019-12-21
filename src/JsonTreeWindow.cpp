#include <iostream>
#include "JsonTreeWindow.h"

JsonTreeWindow::JsonTreeWindow()
        : m_VBox(Gtk::ORIENTATION_VERTICAL),
          m_Button_Quit("Quit"),
          m_Button_Open_File("Open File"),
          openFileWindow() {

    set_title("jsontree");
    set_border_width(5);
    set_default_size(400, 200);

    add(m_VBox);

    //Add the TreeView, inside a ScrolledWindow, with the button underneath:
    m_ScrolledWindow.add(m_TreeView);

    //Only show the scrollbars when they are necessary:
    m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    m_VBox.pack_start(m_ScrolledWindow);
    m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

    m_ButtonBox.pack_start(m_Button_Open_File, Gtk::PACK_SHRINK);
    m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
    m_ButtonBox.set_border_width(5);
    m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);
    m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this, &JsonTreeWindow::on_button_quit));
    m_Button_Open_File.signal_clicked().connect(sigc::mem_fun(*this, &JsonTreeWindow::on_button_load_file));
    m_Button_Open_File.set_margin_right(20);

    //Create the Tree model:
    m_refTreeModel = Gtk::TreeStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);

    //All the items to be reordered with drag-and-drop:
    // m_TreeView.set_reorderable();

    //Fill the TreeView's model
    Gtk::TreeModel::Row row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 1;
    row[m_Columns.m_col_name] = "Billy Bob";

    Gtk::TreeModel::Row childrow = *(m_refTreeModel->append(row.children()));
    childrow[m_Columns.m_col_id] = 11;
    childrow[m_Columns.m_col_name] = "Billy Bob Junior";

    childrow = *(m_refTreeModel->append(row.children()));
    childrow[m_Columns.m_col_id] = 12;
    childrow[m_Columns.m_col_name] = "Sue Bob";

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 2;
    row[m_Columns.m_col_name] = "Joey Jojo";


    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 3;
    row[m_Columns.m_col_name] = "Rob McRoberts";

    childrow = *(m_refTreeModel->append(row.children()));
    childrow[m_Columns.m_col_id] = 31;
    childrow[m_Columns.m_col_name] = "Xavier McRoberts";

    //Add the TreeView's view columns:
    m_TreeView.append_column("ID", m_Columns.m_col_id);
    m_TreeView.append_column("Name", m_Columns.m_col_name);

    //Connect signal:
    m_TreeView.signal_row_activated().connect(sigc::mem_fun(*this,
                                                            &JsonTreeWindow::on_treeview_row_activated));

    show_all_children();
}

JsonTreeWindow::~JsonTreeWindow() {
}

void JsonTreeWindow::on_button_quit() {
    hide();
}

void JsonTreeWindow::on_button_load_file() {
    Gtk::Main::run(openFileWindow);
}

void JsonTreeWindow::on_treeview_row_activated(const Gtk::TreeModel::Path &path,
                                               Gtk::TreeViewColumn * /* column */) {
    Gtk::TreeModel::iterator iter = m_refTreeModel->get_iter(path);
    if (iter) {
        Gtk::TreeModel::Row row = *iter;
        std::cout << "Row activated: ID=" << row[m_Columns.m_col_id] << ", Name="
                  << row[m_Columns.m_col_name] << std::endl;
    }
}