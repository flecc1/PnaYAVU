#include "../headers/file_exception.h"
#include <iostream>

File_exception::File_exception() : My_exception() {}

File_exception::File_exception(int code, const char* msg) : My_exception(code, msg) {}

File_exception::File_exception(const File_exception &other) : My_exception(other) {}

File_exception::~File_exception() {}

void File_exception::printError() const {
    std::cout << "File error ";
    My_exception::printError();
}
