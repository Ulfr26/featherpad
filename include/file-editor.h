#ifndef FILE_EDITOR_H
#define FILE_EDITOR_H

#include <gtkmm.h>
#include "file.h"

class FileEditor : public Gtk::TextView {
    public:
        FileEditor();
        virtual ~FileEditor();
        
        // Action functions
        void new_file();
        void open_file(std::string filename);
        void save_file();

    private:
        File file;
        bool unsaved_changes;
};

#endif //FILE_EDITOR_H
