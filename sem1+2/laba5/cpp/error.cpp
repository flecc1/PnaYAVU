#include "../headers/excep_vvoda.h" 
#include <string>
#include <cctype>
#include <limits>

using namespace std;

inline void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
//функция ввода числа должна иметь в параметре поток
inline int inputNumber(int minVal, int maxVal) 
{
    int num;
    while (true) {
        if (!(cin >> num) || cin.peek() != '\n') {
            cout << "Ошибка ввода! Введите целое число: ";
            clearInputBuffer();
            continue;
        }

        if (num < minVal || num > maxVal) {
            cout << "Число вне диапазона! Допустимо " << minVal << "-" << maxVal << ": ";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return num;
    }
}

inline double inputDouble(double minVal, double maxVal) 
{
    double num;
    while (true) 
    {
        if (!(cin >> num) || cin.peek() != '\n') 
        {
            cout << "Ошибка ввода! Введите число: ";
            clearInputBuffer();
            continue;
        }

        if (num < minVal || num > maxVal) 
        {
            cout << "Число вне диапазона! Допустимо " << minVal << "-" << maxVal << ": ";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();
        return num;
    }
}

inline bool isEnglishText(const string& str) {
    if (str.empty()) return false;
    
    for (unsigned char c : str) {
        if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && 
            c != ' ' && c != '\'' && c != '-') {
            if (c > 127) {
                return false;
            }
        }
    }
    return true;
}

inline bool isValidName(const string& str) {
    if (str.empty()) return false;
    
    for (char c : str) {
        if (c == '&' || c == '?' || c == ',' || c == '!' || c == ';' || 
            c == ':' || c == '*' || c == '%' || c == '$' || c == '#' || 
            c == '@' || c == '<' || c == '>' || c == '=' || c == '+' || 
            c == '~' || c == '`' || c == '|' || c == '\\' || c == '/' ||
            c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
            c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
            return false;
        }
    }
    return true;
}

// Функция для проверки пустой строки или строки только с пробелами
inline bool isOnlySpacesOrEmpty(const string& str) {
    if (str.empty()) return true;
    for (char c : str) {
        if (c != ' ') return false;
    }
    return true;
}

// Функция для проверки пробела в начале строки
inline bool hasLeadingSpace(const string& str) {
    return !str.empty() && str[0] == ' ';
}

inline string readEnglishText() {
    string input;
    getline(cin, input);
    
    if (isOnlySpacesOrEmpty(input)) {
        throw Exp_vvoda(1, "EMPTY_INPUT", "Пустая строка или только пробелы");
    }
    
    if (hasLeadingSpace(input)) {
        throw Exp_vvoda(26, "FORMAT_ERROR", "Строка не должна начинаться с пробела");
    }
    
    if (!isEnglishText(input)) {
        throw Exp_vvoda(2, "LANGUAGE_ERROR", "Допускаются только английские буквы, пробелы, апострофы и дефисы");
    }
    
    if (!isValidName(input)) {
        throw Exp_vvoda(3, "INVALID_CHARS", "Строка содержит запрещенные символы или цифры");
    }
    
    return input;
}

inline string readName() {
        string input;
        getline(cin, input);
        
        if (isOnlySpacesOrEmpty(input)) {
            throw Exp_vvoda(4, "EMPTY_INPUT", "Имя не может быть пустым или содержать только пробелы");
        }
        
        if (hasLeadingSpace(input)) {
            throw Exp_vvoda(27, "FORMAT_ERROR", "Имя не должно начинаться с пробела");
        }
        
        // Проверка на русские символы
        if (!isEnglishText(input)) {
            throw Exp_vvoda(13, "LANGUAGE_ERROR", "Имя должно содержать только английские буквы\nРазрешены: A-Z, a-z, пробелы, апострофы, дефисы");
        }
        
        // Проверка на запрещенные символы
        for (char c : input) {
            if (!isalpha(c) && c != ' ' && c != '-' && c != '\'') {
                throw Exp_vvoda(5, "NAME_FORMAT", "Имя содержит недопустимые символы\nДопустимы только буквы, пробелы и дефисы");
            }
        }
        
        return input;

}

inline string readSurname() {
    string input;
    getline(cin, input);
    
    if (isOnlySpacesOrEmpty(input)) {
        throw Exp_vvoda(7, "EMPTY_INPUT", "Фамилия не может быть пустой или содержать только пробелы");
    }
    
    if (hasLeadingSpace(input)) {
        throw Exp_vvoda(28, "FORMAT_ERROR", "Фамилия не должна начинаться с пробела");
    }
    
    // Проверка на русские символы
    if (!isEnglishText(input)) {
        throw Exp_vvoda(15, "LANGUAGE_ERROR", "Фамилия должна содержать только английские буквы\nРазрешены: A-Z, a-z, пробелы, апострофы, дефисы");
    }
    
    // Проверка на запрещенные символы
    for (char c : input) {
        if (!isalpha(c) && c != ' ' && c != '-' && c != '\'') {
            throw Exp_vvoda(8, "NAME_FORMAT", "Фамилия содержит недопустимые символы\nДопустимы только буквы, пробелы и дефисы");
        }
    }
    
    return input;
}

inline string readString(const char* prompt) 
{
    string input;
    if (prompt && strlen(prompt) > 0) 
    {
        cout << prompt;
    }
    getline(cin, input);
    
    if (isOnlySpacesOrEmpty(input)) 
    {
        throw Exp_vvoda(10, "EMPTY_INPUT", "Пустая строка или только пробелы");
    }
    
    if (hasLeadingSpace(input)) 
    {
        throw Exp_vvoda(29, "FORMAT_ERROR", "Строка не должна начинаться с пробела");
    }
    
    return input;
}