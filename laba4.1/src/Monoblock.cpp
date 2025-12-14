#include "..\headers\Monoblock.h"
#include <iomanip>
#include <iostream>
double Monoblock::getScreenSizeInch()
{
    return screenSizeInch;
}

void Monoblock::setScreenSizeInch(int screenSizeInch)
{
    this->screenSizeInch = screenSizeInch;
}

void Monoblock::printHead()
{
    StationaryMachine::printHead();
    std::cout << std::setw(20) << std::left << "Screen size (inches)"
              << std::endl;
}

void Monoblock::editParametersMenu()
{
     StationaryMachine::editParametersMenu();
    int choice;
    do
    {
        std::cout << "1. set screen size" << std::endl;
        std::cout << "0. skip" << std::endl;
        std::cout << "your choice: ";
        std::cin>>choice;
        std::cin.ignore();
        switch (choice)
        {
        case 1:
        {
            int screenSizeInch;
            std::cin >> screenSizeInch;
            std::cin.ignore();
            // this->screenSizeInch = screenSizeInch;
            setScreenSizeInch(screenSizeInch);
            std::cout << "screen size editinig";
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
Monoblock &Monoblock::operator=(const Monoblock &other)
{
    if (this != &other)
    {
        StationaryMachine::operator=(other);
        screenSizeInch = other.screenSizeInch;
    }
    return *this;
}
bool Monoblock::operator==(const Monoblock &other)
{
    if (!(static_cast<StationaryMachine &>(*this) == static_cast<StationaryMachine>(other)))
        return false;

    if (this->screenSizeInch != -1 && other.screenSizeInch != -1)
        return this->screenSizeInch == other.screenSizeInch;

    return true;
}

std::ostream &operator<<(std::ostream &os, Monoblock &v)
{
    // os << static_cast<StationaryMachine &>(v);
    StationaryMachine &sm = v;
    os << sm;
    os << std::setw(20) << std::left << v.screenSizeInch;
    return os;
}

std::istream &operator>>(std::istream &is, Monoblock &v)
{
    // is >> static_cast<StationaryMachine &>(v);
    StationaryMachine &sm = v;
    is >> sm;
    std::cout << "Screen size (inches)";
    is >> v.screenSizeInch;
    return is;
}
