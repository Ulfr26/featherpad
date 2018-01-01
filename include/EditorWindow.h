#ifndef EDITOR_WINDOW_H 
#define EDITOR_WINDOW_H

#include <gtkmm.h>
#include <string>

class EditorWindow : public Gtk::Window {
    public:
        EditorWindow();
        EditorWindow(std::string filename);
        virtual ~EditorWindow();
    
    protected:
        // Member widgets
        Gtk::Grid grid;
        Gtk::TextView entry;

        /* Action groups (to be expanded)
        Gio::ActionGroup act_file;
        Gio::ActionGroup act_edit;
        Gio::ActionGroup act_search;
        */
};

#endif
