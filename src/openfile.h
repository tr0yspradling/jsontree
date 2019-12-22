#ifndef OPENFILE_H
#define OPENFILE_H

#include <gtkmm.h>
#include <iostream>
#include <string>
#include "utils.h"

class OpenFileWindow : public Gtk::FileChooserDialog {
public:
    OpenFileWindow();

    virtual ~OpenFileWindow();

    std::string filePath;

protected:
    //Signal handlers:
    void on_button_file_clicked();

    //Child widgets:
    Gtk::ButtonBox buttonBox;
    Gtk::Button fileButton;
};

#endif