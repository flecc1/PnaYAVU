#include "..\headers\ComputingMachine.h"
#include <iostream>
#include <iomanip>

char *ComputingMachine::getModel()
{
    return model;
}

char *ComputingMachine::getManufacturer()
{
    return manufacturer;
}

int ComputingMachine::getRam()
{
    return ram;
}

int ComputingMachine::getStorage()
{
    return storage;
}

void ComputingMachine::setModel(char *model)
{
    strcpy_s(this->model, model);
}
void ComputingMachine::setManufacturer(char *manufacturer)
{
    strcpy_s(this->manufacturer, manufacturer);
}

void ComputingMachine::setRam(int ram)
{
    this->ram = ram;
}

void ComputingMachine::setStorage(int storage)
{
    this->storage = storage;
}

void ComputingMachine::editParametersMenu()
{
    int choice;
    do
    {
        std::cout << "1. set model" << std::endl;
        std::cout << "2. set manufacturer" << std::endl;
        std::cout << "3. set ram" << std::endl;
        std::cout << "4. set rom" << std::endl;
        std::cout << "0. skip" << std::endl;
        std::cout << "your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice)
        {
        case 1:
        {
            std::cout << "Enter model: ";
            char model[MAX_LEN];
            std::cin.getline(model, MAX_LEN);
            // std::cin.ignore();
            setModel(model);
            // strcpy_s(this->model, model);
            std::cout << "model editinig";
            break;
        }
        case 2:
        {
            std::cout << "Enter manufacturer: ";
            char manuf[MAX_LEN];
            std::cin.getline(manuf, MAX_LEN);
            std::cin.ignore();

            // strcpy_s(this->manufacturer, manuf);
            setManufacturer(manuf);
            std::cout << "manufactorer editinig";
            break;
        }
        case 3:
        {
            std::cout << "Enter ram: ";
            int ram;
            std::cin >> ram;
            std::cin.ignore();
            // this->ram = ram;
            setRam(ram);
            std::cout << "ram editinig";
            break;
        }
        case 4:
        {
            std::cout << "Enter rom: ";
            int rom;
            std::cin >> rom;
            std::cin.ignore();
            // this->storage = rom;
            setStorage(rom);
            std::cout << "rom editinig";
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
void ComputingMachine::printHead()
{
    std::cout << std::endl
              << std::endl;
    std::cout << std::setw(20) << std::left << "model"
              << std::setw(20) << std::left << "manufacturer"
              << std::setw(5) << std::left << "ram"
              << std::setw(5) << std::left << "rom";
}

ComputingMachine &ComputingMachine::operator=(const ComputingMachine &other)
{
    if (this != &other)
    {
        strcpy_s(this->model, other.model);
        strcpy_s(this->manufacturer, other.manufacturer);
        this->ram = other.ram;
        this->storage = other.storage;
    }
    return *this;
}

bool ComputingMachine::operator==(const ComputingMachine &other)
{
    bool equals = true;
    if (other.model[0] != '\0' && this->model[0] != '\0')
        equals = equals && strcmp(this->model, other.model) == 0;
    if (other.manufacturer[0] != '\0' && this->manufacturer[0] != '\0')
        equals = equals && strcmp(this->manufacturer, other.manufacturer) == 0;
    if (this->storage != -1 && other.storage != -1)
        equals = equals && this->storage == other.storage;
    if (this->ram != -1 && other.ram != -1)
        equals = equals && other.ram == this->ram;
    return equals;
}

std::ostream &operator<<(std::ostream &os, ComputingMachine &v)
{
    // model manuf ram storage
    os << std::setw(20) << std::left << v.model << std::setw(20) << std::left << v.manufacturer << std::setw(5) << std::left << v.ram << std::setw(5) << std::left << v.storage;
    return os;
}

std::istream &operator>>(std::istream &is, ComputingMachine &v)
{
    std::cout << "Enter model: ";
    is.getline(v.model, MAX_LEN);
    std::cout << "Enter manufacturer: ";
    is.getline(v.manufacturer, MAX_LEN);
    std::cout << "Enter RAM (GB): ";
    is >> v.ram;
    std::cout << "Enter ROM (GB): ";
    is >> v.storage;
    return is;
}
