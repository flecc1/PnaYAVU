#ifndef STUDENT_H
#define STUDENT_H
#include "human.h"
class Student: public Human
{
    private:
    double sr_bal;
    int stependiya;
    public:
    Student():Human()
    {
        sr_bal = -1.0;
        stependiya = -1;
    }
    Student(const char* name, const char* sname, int age, double sr_bal, int stependiya):Human(name, sname, age)
    {
        this->sr_bal = sr_bal;
        this->stependiya = stependiya;
    }
    Student(const Student& other) : Human(other)
    {
        this->sr_bal = other.sr_bal;
        this->stependiya = other.stependiya;
    }
    ~Student()
    {

    }
    public:
    void set_sr_bal(double sr_bal);
    void set_stependiya(int stependiya);
    double get_sr_bal()const;
    int get_stependiya()const;
    friend istream &operator>>(istream &in, Student &obj);
    friend ostream &operator<<(ostream &out, Student &obj);
    
    // Операторы для файлов
    friend istream &readFromFile(istream &in, Student &obj);
    friend ostream &writeToFile(ostream &out, const Student &obj);
    
    Student& operator=(const Student &other);
    bool operator==(const Student &other);

    void printHeader() override;
    void edit() override;
};
#endif