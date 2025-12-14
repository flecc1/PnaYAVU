#ifndef FILE_BIN_H
#define FILE_BIN_H

#include "file.h"
#include <string>
#include <fstream>

using namespace std;

template<class T>
class File_bin : public File<T> {
public:
    File_bin(const string& fname);
    
    void write(Ochered<T>& data) override;
    Ochered<T> read() override;
    void display() override;
};

// Подключаем реализацию в конце
#include "../cpp/file_bin.tpp"

#endif