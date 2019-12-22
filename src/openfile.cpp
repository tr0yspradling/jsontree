#include "openfile.h"

OpenFileWindow::OpenFileWindow() : buttonBox(Gtk::ORIENTATION_VERTICAL),
                                   fileButton("Choose File") {
    set_title("Gtk::FileSelection example");

    add(buttonBox);

    buttonBox.pack_start(fileButton);
    fileButton.signal_clicked().connect(sigc::mem_fun(*this,
                                                      &OpenFileWindow::on_button_file_clicked));

    show_all_children();
}

OpenFileWindow::~OpenFileWindow() {};

void OpenFileWindow::on_button_file_clicked() {
    Gtk::FileChooserDialog dialog("Please choose a file",
                                  Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    //Add filters, so that only certain file types can be selected:
    auto filter_json = Gtk::FileFilter::create();
    filter_json->set_name("JSON files");
    filter_json->add_mime_type("application/json");
    dialog.add_filter(filter_json);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    //Show the dialog and wait for a user response:
    int result = dialog.run();

    //Handle the response:
    switch (result) {
        case (Gtk::RESPONSE_OK): {
            //Notice that this is a std::string, not a Glib::ustring.
            std::string filename = dialog.get_filename();
            break;
        }
        case (Gtk::RESPONSE_CANCEL): {
            break;
        }
        default: {
            break;
        }
    }
    hide();
}