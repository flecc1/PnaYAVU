#ifndef FILE_EXCEPTION_H
#define FILE_EXCEPTION_H

#include "excep.h"

class File_exception : public My_exception {
public:
    File_exception();
    File_exception(int code, const char* msg);
    File_exception(const File_exception &other);
    ~File_exception() override;

    void printError() const override;
};

#endif
