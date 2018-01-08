#ifndef EDITOR_WINDOW_H 
#define EDITOR_WINDOW_H

#include <gtkmm.h>
#include <string>
#include "file-editor.h"

class EditorWindow : public Gtk::Window {
    public:
        void init();

        EditorWindow();
        EditorWindow(std::string filename);
        virtual ~EditorWindow();
        
        // Action functions
        void new_file();
        void open_dialog();
        void save_default();
        void save_dialog();
        void quit();

        // General functions
        void save();
        void open_file(std::string filename);
    
    protected:
        // Glade Builder
        Glib::RefPtr<Gtk::Builder> builder;

        // Member widgets
        Gtk::Grid grid;
        FileEditor entry;

        Gtk::MenuBar* menu_bar;

        // Action groups (to be expanded)
        Glib::RefPtr<Gio::SimpleActionGroup> act_file, act_edit, act_help;
};

#endif
