#ifndef EXCEP_H
#define EXCEP_H

#include <cstring>
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <limits>

using namespace::std;
#define S 80

class My_exception
{
protected:
    int error_code;
    char message[S];
    
public:
    My_exception()
    {
        error_code = 0;
        strcpy(message, "");
    }
    
    My_exception(int error_code, const char* new_message)
    {
        this->error_code = error_code;
        strncpy(message, new_message, S - 1);
        message[S - 1] = '\0';
    }
    
    My_exception(const My_exception &other)
    {
        error_code = other.error_code;
        strncpy(message, other.message, S - 1);
        message[S - 1] = '\0';
    }
    
    virtual ~My_exception(){}
    
    virtual void printError()const;
};

#endif