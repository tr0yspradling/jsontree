//
// Created by troy on 12/21/19.
//

#include <gtkmm.h>
#include <iostream>

class OpenFileWindow : public Gtk::Window {
public:
    OpenFileWindow();

    virtual ~OpenFileWindow();

protected:
    //Signal handlers:
    void on_button_file_clicked();

    void on_button_folder_clicked();

    //Child widgets:
    Gtk::ButtonBox buttonBox;
    Gtk::Button fileButton, folderButton;
};
