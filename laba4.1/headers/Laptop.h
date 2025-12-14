#ifndef LAPTOP_H
#define LAPTOP_H
#include <iostream>

#include "Portable.h"
#include "String.h"

class Laptop : public Portable {
private:
    int hasNumPad;

public:
    Laptop(int hasNumPad,
           int batteryCapacitymAh,
           int hasSIM, char* model,
           char* manufactorer,
           int ram, int storage) : Portable(batteryCapacitymAh, hasSIM, model, manufactorer, ram, storage) {
        this->hasNumPad = hasNumPad;
    }
    Laptop() : Portable() {
        hasNumPad = -1;
    }
    Laptop(const Laptop &other) : Portable(other) {
        hasNumPad = other.hasNumPad;
    }
    virtual ~Laptop() = default;
    int getHasNumPad();
    void setHasNumPad(int hasNumPad);
    void printHead() override;
    virtual void editParametersMenu() override; 
    Laptop &operator=(const Laptop &other);
    bool operator==(const Laptop &other);
    friend std::ostream &operator<<(std::ostream &os, Laptop &l);
    friend std::istream &operator>>(std::istream &is, Laptop &l);
};

#endif
