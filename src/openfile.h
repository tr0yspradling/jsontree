#ifndef OPENFILE_H
#define OPENFILE_H

#include <gtkmm.h>
#include <iostream>
#include "rapidjson/document.h"

class OpenFileWindow : public Gtk::Window {
public:
    OpenFileWindow();

    virtual ~OpenFileWindow();

protected:
    //Signal handlers:
    void on_button_file_clicked();

    //Child widgets:
    Gtk::ButtonBox buttonBox;
    Gtk::Button fileButton;
};

#endif