#include "..\headers\Portable.h"
#include "..\headers\ComputingMachine.h"
#include <iostream>
#include <iomanip>
int Portable::getBatteryCapacitymAh()
{
    return batteryCapacitymAh;
}

int Portable::getHasSIM()
{
    return hasSIM;
}

void Portable::setBatteryCapacitymAh(int batteryCapacitymAh)
{
    this->batteryCapacitymAh = batteryCapacitymAh;
}

void Portable::setHasSIM(int hasSIM)
{
    this->hasSIM = hasSIM;
}

void Portable::printHead()
{
    ComputingMachine::printHead();
    std::cout << std::setw(25) << std::left << "Battery Capacity (mAh)"
              << std::setw(30) << std::left << "You can connect a SIM card";
}
void Portable::editParametersMenu()
{

    ComputingMachine::editParametersMenu();
    int choice;
    do
    {
        std::cout << "1. set batary capacity " << std::endl;
        std::cout << "2. set has sim" << std::endl;
        std::cout << "0. skip" << std::endl;
        std::cout << "your choice: ";
        std::cin >> choice;
        switch (choice)
        {

        case 1:
        {
            std::cout << "Enter batary capacity: ";
            int batteryCapacitymAh;
            std::cin >> batteryCapacitymAh;
            // this->batteryCapacitymAh = batteryCapacitymAh;
            setBatteryCapacitymAh(batteryCapacitymAh);
            std::cout << "batary capacity editinig";
            break;
        }
        case 2:
        {
            std::cout << "Enter has sim (1 - yes/ 0 - no): ";
            int hasSIM;
            std::cin >> hasSIM;
            // this->hasSIM = hasSIM;
            setHasSIM(hasSIM);
            std::cout << "uptime hours editinig";
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
Portable &Portable::operator=(const Portable &other)
{
    if (this == &other)
        return *this;
    ComputingMachine::operator=(other);
    batteryCapacitymAh = other.batteryCapacitymAh;
    hasSIM = other.hasSIM;
    return *this;
}
bool Portable::operator==(const Portable &other)
{
    if (!(static_cast<ComputingMachine &>(*this) ==
          static_cast<ComputingMachine>(other)))
        return false;

    bool equals = true;

    if (this->batteryCapacitymAh != -1 && other.batteryCapacitymAh != -1)
        equals = equals && (this->batteryCapacitymAh == other.batteryCapacitymAh);
    if (this->hasSIM != -1 && other.hasSIM != -1)
        equals = equals && (this->hasSIM == other.hasSIM);
    return equals;
}

std::ostream &operator<<(std::ostream &os, Portable &p)
{
    // model manuf ram storage capacity hassim

    os << static_cast<ComputingMachine &>(p);
    os << std::setw(25) << std::left << p.batteryCapacitymAh << std::setw(30) << std::left << (p.hasSIM ? "yes" : "no");
    return os;
}

std::istream &operator>>(std::istream &is, Portable &p)
{
    is >> static_cast<ComputingMachine &>(p);
    std::cout << "enter the battery capacity (mAh): ";
    is >> p.batteryCapacitymAh;
    std::cout << "Do you have a SIM card? (1 - yes/ 2 - no): ";
    int choice;
    is >> choice;
    rewind(stdin);
    p.hasSIM = choice;
    return is;
}
