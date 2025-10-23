#ifndef HEADER_H
#define HEADER_H

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_BLUE "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN "\x1b[36m"
#define COLOR_RESET "\x1b[0m"

#include <iostream>
#include <cstring>
#include<string.h>
using namespace std;

class String
{
    char *str;
    int size;
    char o = '\0';

public:
    String()
    {
        str = nullptr;
        size = 0;
    }
    ~String()
    {
        delete[] str;
    }
    String(int n)
    {
        size = n;
        str = new char[size + 1];
        str[size] = '\0';
    }
    String(const char *cstr)
    {
        this->size = strlen(cstr);
        this->str = new char[size + 1];
        strcpy(this->str, cstr);
    }
    String(const String &obj)
    {
        size = obj.size;
        str = new char[size + 1];   
        for (int i = 0; i < obj.size; i++)
        {
            str[i] = obj.str[i];
        }
        str[size] = '\0';
    }
    String &operator=(const String &other);
    friend istream &operator>>(istream &in, String &str);
    friend ostream &operator<<(ostream &out, const String &str);
    String operator+(const String &other);
    String& operator+=(const String& other);
    String& operator++();
    String& operator--();
    String operator()(int start, int end);
    bool operator<(const String& other) const;
    bool operator>(const String& other) const;
    bool operator==(const String& other) const;
    char& operator[](int ind);
    int getSize() const { return size; }
};
void menu();
#endif