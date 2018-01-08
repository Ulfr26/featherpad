#include "EditorWindow.h"
#include <iostream>

void EditorWindow::init() {
    // Window setup
    set_title("Featherpad - New File");
    set_default_size(1024, 768);
    maximize();

    // Add grid to window
    add(grid);

    // Make sure entry expands
    entry.set_hexpand(true);
    entry.set_vexpand(true);

    // Attach entry to grid
    grid.attach(entry, 0, 1, 1, 1);

    // Initialise action groups
    act_file = Gio::SimpleActionGroup::create();
    act_edit = Gio::SimpleActionGroup::create();
    act_help = Gio::SimpleActionGroup::create();

    act_file->add_action("new", sigc::mem_fun(*this, &EditorWindow::new_file));
    act_file->add_action("open", sigc::mem_fun(*this, &EditorWindow::open_dialog));
    act_file->add_action("save", sigc::mem_fun(*this, &EditorWindow::save));
    act_file->add_action("save-as", sigc::mem_fun(*this, &EditorWindow::save_dialog));
    act_file->add_action("quit", sigc::mem_fun(*this, &EditorWindow::quit));

    insert_action_group("file", act_file);

    // Get menu bar from builder
    builder = Gtk::Builder::create_from_file("glade/menu-bar.glade");
    builder->get_widget("menu-bar", menu_bar);

    grid.attach(*menu_bar, 0, 0, 1, 1);

    show_all_children();
}

EditorWindow::EditorWindow() 
  : entry()
{
    init();    
}

EditorWindow::EditorWindow(std::string filename)
  : entry()
{
    init();
    open_file(filename);
}

EditorWindow::~EditorWindow() {
    // Empty destructor
}

void EditorWindow::new_file() {

}

void EditorWindow::open_dialog() {
    Gtk::FileChooserDialog dialog("Select a file to open");
    dialog.set_transient_for(*this);

    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("Open", Gtk::RESPONSE_OK);

    int result = dialog.run();

    switch(result) {
	    case(Gtk::RESPONSE_OK): {
            open_file(dialog.get_filename());
            break;
	    }

        case (Gtk::RESPONSE_CANCEL): {
            break;
        }

	    default: {
	    	std::cout << "Unexpected input." << std::endl;
	    	break;
	    }
	}
}

void EditorWindow::save_default() {

}

void EditorWindow::save_dialog() {
    Gtk::FileChooserDialog dialog("Select a file to open", Gtk::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("Save", Gtk::RESPONSE_OK);

    int result = dialog.run();

    switch(result) {
	    case(Gtk::RESPONSE_OK): {
            // save(dialog.get_filename());
            // break;
	    }

        case (Gtk::RESPONSE_CANCEL): {
            break;
        }

	    default: {
	    	std::cout << "Unexpected input." << std::endl;
	    	break;
	    }
	}
}

void EditorWindow::quit() {
    exit(0);
}

void EditorWindow::save() {

}

void EditorWindow::open_file(std::string filename) {
    // TODO: check if there is an open file first
    entry.open_file(filename);
}
