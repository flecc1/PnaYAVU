#ifndef HEADER_H
#define HEADER_H
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
#define N 40
class Human
{
    protected:
    char name[N];
    char second_name[N];
    int age;
    public:
    Human()
    {
        name[0] = '\0';
        second_name[0] = '\0';
        age = -1;
    }
    Human(const char* fname, const char *sname, int let)
    {
        this->age = let;
        strncpy(this->name, fname, N);
        strncpy(this->second_name, sname, N);
        name[N-1] = '\0';
        second_name[N-1] = '\0';
    }
    Human(const Human& other)
    {
        strncpy(this->name, other.name, N - 1);
        strncpy(this->second_name, other.second_name, N - 1);
        this->age = other.age;
        this->name[N - 1] = '\0';
        this->second_name[N - 1] = '\0';
    }
    virtual ~Human()
    {

    }
    public:
    int get_age() const;
    const char* get_name() const;
    const char* get_second_name() const;
    void set_age(int n);
    void set_name(const char* new_name);
    void set_second_name(const char* new_second_name);

    Human& operator=(const Human& other);
    bool operator==(const Human &other);
    friend istream &operator>>(istream &in, Human &obj);
    friend ostream &operator<<(ostream &out, const Human &obj);
    virtual void printHeader();
    virtual void edit();
};

#endif
