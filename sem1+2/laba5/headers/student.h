#ifndef STUDENT_H
#define STUDENT_H
#define M 80
#include"human.h"
class Student:public Human
{
    double sr_bal;
    int stependiya;
    public:
    Student():Human()
    {
        sr_bal = -1;
        stependiya = -1;
    }
    Student(const char* name, const char* sname, int age, double sr_bal, int stependiya):Human(name, sname, age)
    {
        this->sr_bal = sr_bal;
        this->stependiya = stependiya;
    }
    Student(const Student& other):Human(other)
    {
        this->sr_bal = other.sr_bal;
        this->stependiya = other.stependiya;
    }
    ~Student()
    {

    }

    void set_sr_bal(double sr_bal);
    void set_stependiya(int stepuha);
    int get_stependiya()const;
    double get_sr_bal()const;
    friend istream& operator>>(istream&in, Student &obj);
    friend ostream& operator<<(ostream& out, Student &obj);
    Student& operator=(const Student &other);
    bool operator==(const Student &other);
    void printHeader() override;
    void edit() override;
};
#endif