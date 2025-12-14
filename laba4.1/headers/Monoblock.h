#ifndef MONOBLOCK_H
#define MONOBLOCK_H

#include "String.h"
#include "StationaryMachine.h"
class Monoblock : public StationaryMachine
{
private:
    double screenSizeInch;

public:
    Monoblock()
    {
        screenSizeInch = -1;
    }
    Monoblock(int screenSizeInch,
              int powerSupplyW, double uptimeHours,
              char *model, char *manufactorer,
              int ram, int storage) : StationaryMachine(powerSupplyW, uptimeHours, model, manufactorer, ram, storage)
    {
        this->screenSizeInch = screenSizeInch;
    }
    Monoblock(const Monoblock &other) : StationaryMachine(other)
    {
        this->screenSizeInch = other.screenSizeInch;
    }
    double getScreenSizeInch();
    void setScreenSizeInch(int screenSizeInch);
    void printHead() override;
    virtual void editParametersMenu() override;
    Monoblock &operator=(const Monoblock &other);
    bool operator==(const Monoblock &other);
    friend std::ostream &operator<<(std::ostream &os, Monoblock &v);
    friend std::istream &operator>>(std::istream &is, Monoblock &v);
    virtual ~Monoblock() = default;
};

#endif