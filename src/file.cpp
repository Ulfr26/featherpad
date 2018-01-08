#include "file.h"
#include <iostream>
#include <string>

File::File(std::string filename) {
    open(filename);
}

File::File() {
}

File::~File() {
    file.close();
}

void File::open(std::string filename) {
    file.close();
    file.open(filename);

    if (!file.is_open())
        std::cerr << "Error opening file" << std::endl;
}

std::string File::read() {
    std::string out;

    if (file) {
        while(!file.eof()) 
            out.push_back(file.get());
    }

    out.erase(out.size()-1);

    return out;
}

void File::write(std::string input) {
    file << input;
}

void File::close() {
    file.close();
}

bool File::is_open() {
    return file.is_open();
}
