#include "../headers/prepod.h"

const char* Prepod::get_dolgnost()const
{
    return this->dolgnost;
}

const char* Prepod::get_specialnost()const
{
    return this->specialnost;
}

const char* Prepod::get_truds()const
{
    return this->truds;
}

void Prepod::set_dolgnost(const char* dolgnost)
{
    strncpy(this->dolgnost, dolgnost, M);
    this->dolgnost[M - 1] = '\0';
}

void Prepod::set_specialnost(const char* specialnost)
{
    strncpy(this->specialnost, specialnost, M);
    this->specialnost[M - 1] = '\0';
}

void Prepod::set_truds(const char* truds)
{
    strncpy(this->truds, truds, M);
    this->truds[M - 1] = '\0';
}

istream& operator>>(istream& in, Prepod&obj)
{
    in >> static_cast<Human&>(obj);
    cout << "введите название должности: ";
    in >> obj.dolgnost;
    cout << "введите название специальности: ";
    in >> obj.specialnost;
    cout << "введите список трудов: ";
    in >> obj.truds;
    return in;
}

ostream& operator<<(ostream& out, Prepod& obj)
{
    out << static_cast<const Human&>(obj);
    out << setw(12) << left << obj.dolgnost 
        << setw(15) << left << obj.specialnost 
        << setw(15) << left << obj.truds;
    return out;
}

Prepod& Prepod::operator=(const Prepod& other)
{
    if (this != &other)
    {
        Human::operator=(other);  // Вызов базового оператора
        strncpy(this->dolgnost, other.dolgnost, M - 1);
        strncpy(this->specialnost, other.specialnost, M - 1);
        strncpy(this->truds, other.truds, M - 1);
        this->dolgnost[M - 1] = '\0';
        this->specialnost[M - 1] = '\0';
        this->truds[M - 1] = '\0';
    }
    return *this;
}

void Prepod::printHeader() 
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_name" 
        << setw(8) << left << "Age"
        << setw(12) << left << "Dolgnost"
        << setw(15) << left << "Specialnost"
        << setw(15) << left << "Truds" << endl;
}