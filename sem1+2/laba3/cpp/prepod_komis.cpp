#include "../headers/prepod_komis.h"

const char* Prepod_Komis::get_spisok_rabot()const
{
    return this->spisok_rabot;
}

void Prepod_Komis::set_spisok_rabot(const char* new_spisok_rabot)
{
    strncpy(this->spisok_rabot, new_spisok_rabot, M - 1);
    this->spisok_rabot[M - 1] = '\0';
}

istream &operator>>(istream &in, Prepod_Komis& obj)
{
    in >> static_cast<Prepod&>(obj);
    cout << "введите имя комисии: ";
    in >> obj.komis_name;
    cout << "введите автобиографию: ";
    in >> obj.autobio;
    cout << "введите что делает член комисии: ";
    in >> obj.spisok_rabot;
    return in;
}

ostream &operator<<(ostream &out, Prepod_Komis& obj)
{
    out << static_cast<Prepod&>(obj);
    out << setw(15) << left << obj.komis_name << setw(20) << left << obj.autobio;
    out << setw(20) << left << obj.spisok_rabot;
    return out;
}

Prepod_Komis& Prepod_Komis::operator=(const Prepod_Komis& other)
{
    if (this != &other)
    {
        Prepod::operator=(other);  // Вызов через одного родителя
        Komisia::operator=(other); // Вызов через другого родителя
        strncpy(this->spisok_rabot, other.spisok_rabot, M - 1);
        this->spisok_rabot[M - 1] = '\0';
    }
    return *this;
}

void Prepod_Komis::printHeader() 
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_name" 
        << setw(8) << left << "Age"
        << setw(12) << left << "Dolgnost"
        << setw(15) << left << "Specialnost"
        << setw(15) << left << "Truds"
        << setw(15) << left << "Komisiya"
        << setw(20) << left << "Autobio" 
        << setw(20) << left << "Spisok_rabot" << endl;
