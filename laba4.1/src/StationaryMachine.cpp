#include "../headers/StationaryMachine.h"
#include <iomanip>
#include <iostream>

int StationaryMachine::getPowerSupplyW()
{
    return powerSupplyW;
}

double StationaryMachine::getUptimeHours()
{
    return uptimeHours;
}

void StationaryMachine::setPowerSupplyW(int powerSupplyW)
{
    this->powerSupplyW = powerSupplyW;
}

void StationaryMachine::setUptimeHours(double uptimeHours)
{
    this->uptimeHours = uptimeHours;
}

StationaryMachine &StationaryMachine::operator=(const StationaryMachine &other)
{
    if (this != &other)
    {
        ComputingMachine::operator=(other);
        this->powerSupplyW = other.powerSupplyW;
        this->uptimeHours = other.uptimeHours;
    }
    return *this;
}

void StationaryMachine::printHead()
{
    ComputingMachine::printHead();

    std::cout << std::setw(20) << std::left << "charging power (W)"
              << std::setw(20) << std::left << "hours of operation";
}

void StationaryMachine::editParametersMenu()
{
    ComputingMachine::editParametersMenu();
    int choice;
    do
    {
        std::cout << "1. set power supply" << std::endl;
        std::cout << "2. set uptime hours" << std::endl;
        std::cout << "0. skip" << std::endl;
        std::cout << "your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice)
        {

        case 1:
        {
            std::cout << "Enter power supply: ";
            int powerSupplyW;
            std::cin >> powerSupplyW;
            std::cin.ignore();
            // this->powerSupplyW = powerSupplyW;
            setPowerSupplyW(powerSupplyW);
            std::cout << "power supply editinig";
            break;
        }
        case 2:
        {
            std::cout << "Enter uptime hours: ";
            int uptimeHours;
            std::cin >> uptimeHours;
            std::cin.ignore();
            // this->uptimeHours = uptimeHours;
            setUptimeHours(uptimeHours);
            std::cout << "uptime hours editinig";
            break;
        }
        case 0:
        {
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
bool StationaryMachine::operator==(const StationaryMachine &other)
{
    if (!ComputingMachine::operator==(other))
        return false;
    bool equals = true;
    if (this->powerSupplyW != -1 && other.powerSupplyW != -1)
        equals = equals && this->powerSupplyW == other.powerSupplyW;

    if (this->uptimeHours != -1 && other.uptimeHours != -1)
        equals = equals && this->uptimeHours == other.uptimeHours;
    return equals;
}
std::ostream &operator<<(std::ostream &os, StationaryMachine &v)
{
    // os << static_cast<ComputingMachine &>(v);
    ComputingMachine &cm = v;
    // model manuf ram storage powerSup uptime

    os << cm;
    os << std::setw(20) << std::left << v.powerSupplyW << std::setw(20) << std::left << v.uptimeHours;
    return os;
}

std::istream &operator>>(std::istream &is, StationaryMachine &v)
{
    // is >> static_cast<ComputingMachine &>(v);
    ComputingMachine &cm = v;
    is >> cm;
    std::cout << "Enter the charging power (W): ";
    is >> v.powerSupplyW;
    std::cout << "Enter the number of hours of operation: ";
    is >> v.uptimeHours;
    return is;
}
