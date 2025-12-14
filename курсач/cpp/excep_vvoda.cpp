#include "../headers/excep_vvoda.h"
#include <string>
#include <cctype>
#include <limits>
#include <cstring>

using namespace std;

void Exp_vvoda::printError()const
{
    cout << "Ошибка ввода [" << error_type << "] " << error_code << ":\n" << message << endl;
}

string Exp_vvoda::inputName(istream& in) const
{
    string input;
    while (true) {
        try {
            // Очищаем буфер перед вводом, если там есть символ новой строки
            if (in.peek() == '\n') {
                in.ignore();
            }
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

string Exp_vvoda::inputSurname(istream& in) const
{
    string input;
    while (true) {
        try {
            // Очищаем буфер перед вводом, если там есть символ новой строки
            if (in.peek() == '\n') {
                in.ignore();
            }
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

string Exp_vvoda::inputString(const char* prompt, istream& in) const
{
    string input;
    while (true) {
        try {
            // Очищаем буфер перед вводом, если там есть символ новой строки
            if (in.peek() == '\n') {
                in.ignore();
            }
            
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
            
            // Проверка на английские символы
            for (unsigned char c : input) {
                if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && 
                    c != ' ' && c != '\'' && c != '-' && !(c >= '0' && c <= '9')) {
                    if (c > 127) {
                        throw Exp_vvoda(16, "LANGUAGE_ERROR", "Строка должна содержать только английские буквы, цифры и пробелы");
                    }
                }
            }
            
            // Проверка на запрещенные символы (разрешаем буквы, цифры, пробелы, дефис, апостроф)
            for (char c : input) {
                if (!isalnum(c) && c != ' ' && c != '-' && c != '\'') {
                    throw Exp_vvoda(11, "STRING_FORMAT", "Строка содержит недопустимые символы");
                }
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

int Exp_vvoda::inputNumber(istream& in, int minVal, int maxVal) const
{
    int num;
    while (true) {
        try {
            if (in.peek() == '\n') {
                throw My_exception(32, "Ошибка ввода! нельзя ничего не ввести");
            }
            if (in.peek() == ' ') {
                throw My_exception(33, "Ошибка ввода! нельзя ввести пробел");
            }
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

double Exp_vvoda::inputDouble(istream& in, double minVal, double maxVal) const
{
    double num;
    while (true) {
        try {
            if (in.peek() == '\n') {
                throw My_exception(32, "Ошибка ввода! Введите целое число с точкой (nelzya pust stroku)");
            }
            if (in.peek() == ' ') {
                throw My_exception(33, "Ошибка ввода! нельзя ввести пробел");
            }
            if (!(in >> num) || in.peek() != '\n') {
                throw My_exception(32, "Ошибка ввода! Введите число c точкой");
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

