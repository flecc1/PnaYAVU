#include "../headers/student.h"

void Student::set_sr_bal(double sr_bal)
{
    this->sr_bal = sr_bal;
}

void Student::set_stependiya(int stepuha)
{
    this->stependiya = stepuha;
}

double Student::get_sr_bal()const
{
    return this->sr_bal;
}

int Student::get_stependiya()const
{
    return this->stependiya;
}

istream& operator>>(istream &in, Student &obj)
{
    in >> static_cast<Human&>(obj);
    cout << "введите средний бал: ";
    in >> obj.sr_bal;
    cout << "введите степендию: ";
    in >> obj.stependiya;
    return in;
}

ostream& operator<<(ostream& out, Student &obj)
{
    out << static_cast<const Human&>(obj);
    out << setw(12) << left << obj.sr_bal << setw(12) << left << obj.stependiya;
    return out;
}

Student& Student::operator=(const Student &other)
{
    if(this != &other)
    {
        Human::operator=(other);
        this->sr_bal = other.sr_bal;
        this->stependiya = other.stependiya;
    }
    return *this;
}

void Student::printHeader() 
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_name" 
        << setw(8) << left << "Age"
        << setw(12) << left << "Sr_bal"       
        << setw(12) << left << "Stipendiya" << endl; 
}
