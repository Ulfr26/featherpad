#ifndef FILE_H
#define FILE_H

#include <fstream>

class File {
    public:
        File(std::string filename);
        File();
        ~File();

        void open(std::string filename);
        std::string read();
        void write(std::string input);
        void close();
        bool is_open();

    private:
        std::fstream file;
};

#endif //FILE_H
