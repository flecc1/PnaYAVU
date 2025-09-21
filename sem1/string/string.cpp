#include "header.h"

String &String::operator=(const String &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] str;
    size = other.size;
    str = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        str[i] = other.str[i];
    }
    str[size] = '\0';
    return *this;
}

String String::operator+(const String &other)
{
    String result;
    result.size = this->size + other.size;
    result.str = new char[result.size + 1];
    strcpy(result.str, this->str);
    strcat(result.str, other.str);
    return result;
}
String& String::operator+=(const String &other)
{
    String temp = *this + other;
    delete[] this->str;
    size = temp.size;
    str = new char[size + 1];
    strcpy(this->str, temp.str);
    return *this;
}

String String::operator()(int start, int end)
{
    if (start < 0 || start >= size || end < 0 || start + end > size)
    {
        cout<<"недопустимые параметры начала и конца строки"<<endl;
        return String("");
    }
    if (end >= 80)
    {
        cout <<"слишком длинная подстрока"<<endl;
        return String("");
    }
    char buffer[80];
    strncpy(buffer, str + start, end);
    buffer[end] = '\0';
    return String(buffer);
}

bool String::operator<(const String& other) const
{
    if (this->str == nullptr || other.str == nullptr)
        return false;
    return strcmp(this->str, other.str) < 0;
}

bool String::operator>(const String& other) const
{
    if (this->str == nullptr || other.str == nullptr)
        return false;
    return strcmp(this->str, other.str) > 0;
}

bool String::operator==(const String& other) const
{
    if (str == nullptr || other.str == nullptr)
        return false;
    return std::strcmp(str, other.str) == 0;
}


istream &operator>>(istream &in, String &str)
{
    char buffer[80];
    in >> buffer;
    delete[] str.str;
    str.size = strlen(buffer);
    str.str = new char[str.size + 1];
    strcpy(str.str, buffer);
    return in;
}

ostream &operator<<(ostream &out, const String &str)
{
    if (str.str != nullptr)
    {
        out << str.str;
    }
    return out;
}