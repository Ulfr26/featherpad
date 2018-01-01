#include "EditorWindow.h"

EditorWindow::EditorWindow() 
  : entry()
{
    // Set title
    set_title("Featherpad - New File");

    // Set default size
    set_default_size(1024, 768);

    // Add grid to window
    add(grid);

    // Make sure entry expands
    entry.set_hexpand(true);
    entry.set_vexpand(true);

    // Attach entry to grid
    grid.attach(entry, 0, 0, 1, 1);

    show_all_children();
}

EditorWindow::EditorWindow(std::string filename)
  : entry()
{
    // Set title (will be changed in the open_file method later
    set_title("Featherpad");
    
    // Add grid to window
    add(grid);

    // Attach entry to grid
    grid.attach(entry, 0, 0, 1, 1);

    show_all_children();

    // open_file(filename);
}

EditorWindow::~EditorWindow() {
    // Empty destructor
}
