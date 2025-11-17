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
    
    // Методы проверки строк (с циклами внутри) - убрали static
    string inputName(istream& in = cin) const
    {
        string input;
        while (true) {
            try {
                getline(in, input);
                
                if (input.empty() || input.find_first_not_of(' ') == string::npos) {
                    throw Exp_vvoda(4, "EMPTY_INPUT", "Имя не может быть пустым или содержать только пробелы");
                }
                
                if (input[0] == ' ') {
                    throw Exp_vvoda(27, "FORMAT_ERROR", "Имя не должно начинаться с пробела");
                }
                
                // Проверка на английские символы
                for (unsigned char c : input) {
                    if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && 
                        c != ' ' && c != '\'' && c != '-') {
                        if (c > 127) {
                            throw Exp_vvoda(13, "LANGUAGE_ERROR", "Имя должно содержать только английские буквы");
                        }
                    }
                }
                
                // Проверка на запрещенные символы
                for (char c : input) {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'') {
                        throw Exp_vvoda(5, "NAME_FORMAT", "Имя содержит недопустимые символы");
                    }
                }
                
                return input;
            } catch (Exp_vvoda& e) {
                cout << "Ошибка при вводе имени: ";
                e.printError();
                cout << "Повторите ввод имени: ";
            }
        }
    }
    
    string inputSurname(istream& in = cin) const
    {
        string input;
        while (true) {
            try {
                getline(in, input);
                
                if (input.empty() || input.find_first_not_of(' ') == string::npos) {
                    throw Exp_vvoda(7, "EMPTY_INPUT", "Фамилия не может быть пустой или содержать только пробелы");
                }
                
                if (input[0] == ' ') {
                    throw Exp_vvoda(28, "FORMAT_ERROR", "Фамилия не должна начинаться с пробела");
                }
                
                // Проверка на английские символы
                for (unsigned char c : input) {
                    if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && 
                        c != ' ' && c != '\'' && c != '-') {
                        if (c > 127) {
                            throw Exp_vvoda(15, "LANGUAGE_ERROR", "Фамилия должна содержать только английские буквы");
                        }
                    }
                }
                
                // Проверка на запрещенные символы
                for (char c : input) {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'') {
                        throw Exp_vvoda(8, "NAME_FORMAT", "Фамилия содержит недопустимые символы");
                    }
                }
                
                return input;
            } catch (Exp_vvoda& e) {
                cout << "Ошибка при вводе фамилии: ";
                e.printError();
                cout << "Повторите ввод фамилии: ";
            }
        }
    }
    
    string inputString(const char* prompt, istream& in = cin) const
    {
        string input;
        while (true) {
            try {
                if (prompt && strlen(prompt) > 0) {
                    cout << prompt;
                }
                getline(in, input);
                
                if (input.empty() || input.find_first_not_of(' ') == string::npos) {
                    throw Exp_vvoda(10, "EMPTY_INPUT", "Пустая строка или только пробелы");
                }
                
                if (input[0] == ' ') {
                    throw Exp_vvoda(29, "FORMAT_ERROR", "Строка не должна начинаться с пробела");
                }
                
                return input;
            } catch (Exp_vvoda& e) {
                cout << "Ошибка при вводе: ";
                e.printError();
                if (prompt && strlen(prompt) > 0) {
                    cout << prompt;
                }
            }
        }
    }
};

#endif