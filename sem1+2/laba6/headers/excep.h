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
    
    // Методы проверки ввода (с циклами внутри) - убрали static
    int inputNumber(istream& in, int minVal, int maxVal) const
    {
        int num;
        while (true) {
            try {
                if (!(in >> num) || in.peek() != '\n') {
                    throw My_exception(30, "Ошибка ввода! Введите целое число");
                }

                if (num < minVal || num > maxVal) {
                    throw My_exception(31, ("Число вне диапазона! Допустимо " + to_string(minVal) + "-" + to_string(maxVal)).c_str());
                }

                in.ignore(numeric_limits<streamsize>::max(), '\n');
                return num;
            } catch (My_exception& e) {
                cout << "Ошибка: ";
                e.printError();
                cout << "Повторите ввод: ";
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    
    double inputDouble(istream& in, double minVal, double maxVal) const
    {
        double num;
        while (true) {
            try {
                if (!(in >> num) || in.peek() != '\n') {
                    throw My_exception(32, "Ошибка ввода! Введите число");
                }

                if (num < minVal || num > maxVal) {
                    throw My_exception(33, ("Число вне диапазона! Допустимо " + to_string(minVal) + "-" + to_string(maxVal)).c_str());
                }

                in.ignore(numeric_limits<streamsize>::max(), '\n');
                return num;
            } catch (My_exception& e) {
                cout << "Ошибка: ";
                e.printError();
                cout << "Повторите ввод: ";
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    
    // Перегрузки для cin по умолчанию
    int inputNumber(int minVal, int maxVal) const
    {
        return inputNumber(cin, minVal, maxVal);
    }
    
    double inputDouble(double minVal, double maxVal) const
    {
        return inputDouble(cin, minVal, maxVal);
    }
};

#endif