#include "..\headers\Laptop.h"
#include <iostream>
#include <conio.h>
#include <iomanip>

int Laptop::getHasNumPad()
{
    return hasNumPad;
}

void Laptop::setHasNumPad(int hasNumPad)
{
    this->hasNumPad = hasNumPad;
}

void Laptop::printHead()
{
    Portable::printHead();
    std::cout << std::setw(15) << std::left << "Is there a Numpad" << std::endl;
}

void Laptop::editParametersMenu()
{
    Portable::editParametersMenu();
    int choice;
    do
    {
        std::cout << "1. set has numpad " << std::endl;
        std::cout << "0. skip" << std::endl;
        std::cout << "your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter has numpad(1 - yes/ 0 - no): ";
            int hasNumpad;
            std::cin >> hasNumpad;
            // this->hasSIM = hasSIM;
            setHasNumPad(hasNumpad);
            std::cout << "has numpad editinig";
            break;
        }
        case 0:{
            break;
        }
        default:
        {
            std::cout << "error choice" << std::endl;
            break;
        }
        }
    } while (choice != 0);
}
Laptop &Laptop::operator=(const Laptop &other)
{
    if (this != &other)
    {
        Portable::operator=(other);
        hasNumPad = other.hasNumPad;
    }
    return *this;
}

bool Laptop::operator==(const Laptop &other)
{
    if (!(static_cast<Portable &>(*this) ==
          static_cast<Portable>(other)))
        return false;
    if (this->hasNumPad != -1 && other.hasNumPad != -1)
        return this->hasNumPad == other.hasNumPad;
    return true;
}

std::ostream &operator<<(std::ostream &os, Laptop &l)
{
    // os << static_cast<Portable &>(l) << std::endl;
    //  model manuf ram storage capacity hassim hasNUm

    Portable &p = l;
    os << p;
    os << std::setw(15) << std::left << (l.hasNumPad == 1 ? "yes" : "no");
    return os;
}

std::istream &operator>>(std::istream &is, Laptop &l)
{
    // is >> static_cast<Portable &>(l);
    Portable &p = l;
    is >> p;
    std::cout << "Is there a Nampad(1 - yes/ 2 - no): ";
    // char choice = _getch();
    int choice;
    is >> choice;
    rewind(stdin);
    l.hasNumPad = choice;
    return is;
}
