#ifndef COMPUTING_MACHINE_H
#define COMPUTING_MACHINE_H

#include <cstring>
#include<iostream>
#define MAX_LEN 20
class ComputingMachine
{

private:
    char model[MAX_LEN];
    char manufacturer[MAX_LEN];
    int ram;
    int storage;

public:
    ComputingMachine()
    {
        model[0] = '\0';
        manufacturer[0] = '\0';
        ram = -1;
        storage = -1;
    }

    ComputingMachine(char *model, char *manufactorer, int ram, int storage)
    {
        strcpy_s(this->model, model);
        strcpy_s(this->manufacturer, manufactorer);
        this->ram = ram;
        this->storage = storage;
    }

    ComputingMachine(const ComputingMachine &other)
    {
        strcpy_s(this->model, other.model);
        strcpy_s(this->manufacturer, other.manufacturer);
        this->ram = other.ram;
        this->storage = other.storage;
    }

    virtual ~ComputingMachine() = default;

    char*  getModel();
    char* getManufacturer();
    int getRam();
    int getStorage();

    void setModel(char* model);
    void setManufacturer(char* manufacturer);
    void setRam(int ram);
    void setStorage(int storage);

    virtual void editParametersMenu();
    virtual void printHead();

    ComputingMachine &operator=(const ComputingMachine &other);
    bool operator==(const ComputingMachine &other);
    friend std::ostream &operator<<(std::ostream &os, ComputingMachine &v);
    friend std::istream &operator>>(std::istream &is, ComputingMachine &v);
};

#endif