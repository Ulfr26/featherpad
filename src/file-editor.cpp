#include "file-editor.h"
#include <gtkmm.h>
#include <iostream>
#include <fstream>

FileEditor::FileEditor() {
    unsaved_changes = false;
    new_file();
}

FileEditor::~FileEditor() {
    file.close();
}

void FileEditor::new_file() {
    unsaved_changes = false;
    file.close();

    set_buffer(Gtk::TextBuffer::create());
}

void FileEditor::open_file(std::string filename) {
    file.close(); 
    file.open(filename);

    auto buf = Gtk::TextBuffer::create();
    buf->set_text(file.read());
    set_buffer(buf);
}

void FileEditor::save_file() {
    if (!file.is_open())
        return;

    file.write(get_buffer()->get_text());
}
