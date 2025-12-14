#include "..\headers\Tablet.h"
#include "..\headers\Portable.h"

#include <iostream>
#include <conio.h>
#include <iomanip>

int Tablet::getDetachableKeyboard()
{
    return detachableKeyboard;
}

void Tablet::setDetachableKeyboard(int detachableKeyboard)
{
    this->detachableKeyboard = detachableKeyboard;
}

void Tablet::printHead()
{
    Portable::printHead();
    std::cout << std::setw(30) << std::left << "Keyboard can be connected" << std::endl;
}

void Tablet::editParametersMenu()
{
    Portable::editParametersMenu();
    int choice;
    do
    {
        std::cout << "1. set detacheble keyboard " << std::endl;
        std::cout << "0. skip" << std::endl;
        std::cout << "your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter keyboard can be connected(1 - yes/ 0 - no): ";
            int detachable;
            std::cin >> detachable;
            // this->hasSIM = hasSIM;
            setDetachableKeyboard(detachable);
            std::cout << "detachable editinig";
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
Tablet &Tablet::operator=(const Tablet &other)
{
    if (this != &other)
    {
        Portable::operator=(other);
        this->detachableKeyboard = other.detachableKeyboard;
    }
    return *this;
}

bool Tablet::operator==(const Tablet &other)
{

    if (!(static_cast<Portable &>(*this) == static_cast<Portable>(other)))
        return false;

    if (this->detachableKeyboard != -1 && other.detachableKeyboard != -1)
        return this->detachableKeyboard == other.detachableKeyboard;

    return true;
}

std::ostream &operator<<(std::ostream &os, Tablet &t)
{
    // os << static_cast<Portable &>(t);
    // model manuf ram storage capacity hassim detachbaleKey

    Portable &p = t;
    os << p;
    os << std::setw(30) << std::left << (t.detachableKeyboard == 1 ? "yes" : "no");
    return os;
}

std::istream &operator>>(std::istream &is, Tablet &t)
{
    // is >> static_cast<Portable &>(t);
    Portable &p = t;
    is >> p;
    std::cout << "Is it possible to connect a keyboard:(1 - yes/ 2 - no): ";
    // char choice = _getch();
    int choice;
    is >> choice;
    rewind(stdin);
    t.detachableKeyboard = choice;
    std::cout << std::endl;
    return is;
}
