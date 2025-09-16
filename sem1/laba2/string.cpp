#include <iostream>

class String
{
    char *str;
    int size;

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
        str = new char[size];
    }
    String(const String &obj)
    {
        size = obj.size;
        str = new char[size];
        for (int i = 0; i < obj.size; i++)
        {
            str[i] = obj.str[i];
        }
    }
};