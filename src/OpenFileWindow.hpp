//
// Created by troy on 12/21/19.
//

#include <gtkmm.h>
#include <iostream>

class OpenFileWindow : public Gtk::Window {
public:
    OpenFileWindow() : m_ButtonBox(Gtk::ORIENTATION_VERTICAL),
                       m_Button_File("Choose File"),
                       m_Button_Folder("Choose Folder") {
        set_title("Gtk::FileSelection example");

        add(m_ButtonBox);

        m_ButtonBox.pack_start(m_Button_File);
        m_Button_File.signal_clicked().connect(sigc::mem_fun(*this,
                                                             &OpenFileWindow::on_button_file_clicked));

        m_ButtonBox.pack_start(m_Button_Folder);
        m_Button_Folder.signal_clicked().connect(sigc::mem_fun(*this,
                                                               &OpenFileWindow::on_button_folder_clicked));

        show_all_children();
    }

    virtual ~OpenFileWindow() {};

protected:
    //Signal handlers:
    void on_button_file_clicked() {
        Gtk::FileChooserDialog dialog("Please choose a file",
                                      Gtk::FILE_CHOOSER_ACTION_OPEN);
        dialog.set_transient_for(*this);

        //Add response buttons the the dialog:
        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("_Open", Gtk::RESPONSE_OK);

        //Add filters, so that only certain file types can be selected:

        auto filter_text = Gtk::FileFilter::create();
        filter_text->set_name("Text files");
        filter_text->add_mime_type("text/plain");
        dialog.add_filter(filter_text);

        auto filter_cpp = Gtk::FileFilter::create();
        filter_cpp->set_name("C/C++ files");
        filter_cpp->add_mime_type("text/x-c");
        filter_cpp->add_mime_type("text/x-c++");
        filter_cpp->add_mime_type("text/x-c-header");
        dialog.add_filter(filter_cpp);

        auto filter_any = Gtk::FileFilter::create();
        filter_any->set_name("Any files");
        filter_any->add_pattern("*");
        dialog.add_filter(filter_any);

        //Show the dialog and wait for a user response:
        int result = dialog.run();

        //Handle the response:
        switch (result) {
            case (Gtk::RESPONSE_OK): {
                std::cout << "Open clicked." << std::endl;

                //Notice that this is a std::string, not a Glib::ustring.
                std::string filename = dialog.get_filename();
                std::cout << "File selected: " << filename << std::endl;
                break;
            }
            case (Gtk::RESPONSE_CANCEL): {
                std::cout << "Cancel clicked." << std::endl;
                break;
            }
            default: {
                std::cout << "Unexpected button clicked." << std::endl;
                break;
            }
        }
        hide();
    }

    void on_button_folder_clicked() {
        Gtk::FileChooserDialog dialog("Please choose a folder",
                                      Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
        dialog.set_transient_for(*this);

        //Add response buttons the the dialog:
        dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
        dialog.add_button("Select", Gtk::RESPONSE_OK);

        int result = dialog.run();

        //Handle the response:
        switch (result) {
            case (Gtk::RESPONSE_OK): {
                std::cout << "Select clicked." << std::endl;
                std::cout << "Folder selected: " << dialog.get_filename()
                          << std::endl;
                break;
            }
            case (Gtk::RESPONSE_CANCEL): {
                std::cout << "Cancel clicked." << std::endl;
                break;
            }
            default: {
                std::cout << "Unexpected button clicked." << std::endl;
                break;
            }
        }
        hide();
    }

    //Child widgets:
    Gtk::ButtonBox m_ButtonBox;
    Gtk::Button m_Button_File, m_Button_Folder;
};