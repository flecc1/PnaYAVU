#ifndef EXCEP_VVODA_H
#define EXCEP_VVODA_H

#include "excep.h"

class Exp_vvoda : public My_exception
{
    char error_type[S];
    
public:
    Exp_vvoda():My_exception()
    {
        strcpy(error_type, "");
    }
    
    Exp_vvoda(int code, const char *error_type, const char* message) 
        : My_exception(code, message)
    {
        strncpy(this->error_type, error_type, S - 1);
        this->error_type[S - 1] = '\0';
    }
    
    Exp_vvoda(const Exp_vvoda& other) : My_exception(other) 
    {
        strncpy(error_type, other.error_type, S - 1);
        error_type[S - 1] = '\0';
    }
    
    void printError()const override;
    string inputName(istream& in = cin) const;
    string inputSurname(istream& in = cin) const;
    string inputString(const char* prompt, istream& in = cin) const;
    string inputFilename(const char* prompt, istream& in = cin) const;

    int inputNumber(istream& in, int minVal, int maxVal) const;
    double inputDouble(istream& in, double minVal, double maxVal) const;
};

#endif

