#include "../headers/komis.h"

const char* Komisia::get_komis_name()const
{
    return this->komis_name;
}


const char* Komisia::get_autobio()const
{
    return this->autobio;
}

void Komisia::set_komis_name(const char* kname)
{
    strncpy(this->komis_name, kname, M);
    this->komis_name[M - 1] = '\0';
}

void Komisia::set_autobio(const char* bio)
{
    strncpy(this->autobio, bio, M);
    this->autobio[M - 1] = '\0';
}

istream &operator>>(istream &in, Komisia &obj)
{
    in >> static_cast<Human&>(obj);
    cout << "введите имя комисии: ";
    in >> obj.komis_name;
    cout << "введите автобиографию: ";
    in >> obj.autobio;
    return in;
}

ostream &operator<<(ostream& out, Komisia &obj)
{
    out << static_cast<const Human&>(obj);
    out << setw(15) << left << obj.komis_name << setw(20) << left << obj.autobio;
    return out;
}

Komisia& Komisia::operator=(const Komisia& other)
{
    if (this != &other)
    {
        Human::operator=(other);
        strncpy(this->komis_name, other.komis_name, M);
        strncpy(this->autobio, other.autobio, M);
        this->komis_name[M - 1] = '\0';
        this->autobio[M - 1] = '\0';
    }
    return *this;
}


void Komisia::printHeader() 
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_Name" 
        << setw(8) << left << "Age"
        << setw(15) << left << "Komisiya"
        << setw(20) << left << "Autobio" << endl;
}