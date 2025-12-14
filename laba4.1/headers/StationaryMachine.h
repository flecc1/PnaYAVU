#ifndef STATIONARY_MACHINE_H
#define STATIONARY_MACHINE_H

#include "ComputingMachine.h"
class StationaryMachine : public ComputingMachine
{
private:
    int powerSupplyW;
    double uptimeHours;

public:
    StationaryMachine()
    {
        powerSupplyW = -1;
        uptimeHours = -1;
    }
    StationaryMachine(int powerSupplyW, double uptimeHours,
                      char *model, char *manufactorer,
                      int ram, int storage) : ComputingMachine(model, manufactorer, ram, storage)
    {
        this->powerSupplyW = powerSupplyW;
        this->uptimeHours = uptimeHours;
    }
    StationaryMachine(const StationaryMachine &other) : ComputingMachine(other)
    {
        this->powerSupplyW = other.powerSupplyW;
        this->uptimeHours = other.uptimeHours;
    }
    int getPowerSupplyW();
    double getUptimeHours();
    void setPowerSupplyW(int powerSupplyW);
    void setUptimeHours(double uptimeHours);
    virtual void printHead() override;
    virtual void editParametersMenu() override;
    StationaryMachine &operator=(const StationaryMachine &other);
    bool operator==(const StationaryMachine &other);
    friend std::ostream &operator<<(std::ostream &os, StationaryMachine &v);
    friend std::istream &operator>>(std::istream &is, StationaryMachine &v);
    virtual ~StationaryMachine() = default;
};

#endif