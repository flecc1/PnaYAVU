#ifndef FILE_H
#define FILE_H

#include "ochered.h"
#include <string>
#include <fstream>

using namespace std;

template<class T>
class File {
protected:
    string filename;
    
public:
    File(const string& fname) : filename(fname) {}
    virtual ~File() {}
    
    virtual void write(Ochered<T>& data) = 0;
    virtual Ochered<T> read() = 0;
    virtual void display() = 0;
    
    string getFilename() const { return filename; }
};

#endif

