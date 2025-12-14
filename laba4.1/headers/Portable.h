#ifndef PORTABLE_H
#define PORTABLE_H
#include "ComputingMachine.h"
class Portable : public ComputingMachine
{
private:
    int batteryCapacitymAh;
    int hasSIM;

public:
    Portable() : ComputingMachine()
    {
        batteryCapacitymAh = -1;
        hasSIM = -1;
    }
    Portable(int batteryCapacitymAh,
             int hasSIM, char *model,
             char *manufactorer,
             int ram, int storage) : ComputingMachine(model, manufactorer, ram, storage)
    {
        this->batteryCapacitymAh = batteryCapacitymAh;
        this->hasSIM = hasSIM;
    }

    Portable(const Portable &other) : ComputingMachine(other)
    {
        batteryCapacitymAh = other.batteryCapacitymAh;
        hasSIM = other.hasSIM;
    }
    ~Portable() = default;
    int getBatteryCapacitymAh();
    int getHasSIM();
    void setBatteryCapacitymAh(int batteryCapacitymAh);
    void setHasSIM(int hasSIM);
    virtual void printHead() override;
    virtual void editParametersMenu() override;
    Portable &operator=(const Portable &other);
    bool operator==(const Portable &other);
    friend std::ostream &operator<<(std::ostream &os, Portable &v);
    friend std::istream &operator>>(std::istream &is, Portable &v);
};

#endif