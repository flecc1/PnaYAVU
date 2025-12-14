#ifndef FILE_TXT_H
#define FILE_TXT_H

#include "file.h"
#include <string>
#include <fstream>

using namespace std;

template<class T>
class File_txt : public File<T> {
public:
    File_txt(const string& fname);
    
    void write(Ochered<T>& data) override;
    Ochered<T> read() override;
    void display() override;
};

// Подключаем реализацию в конце
#include "../cpp/file_txt.tpp"

#endif