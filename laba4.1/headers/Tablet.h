#ifndef TABLET_H
#define TABLET_H
#include "Portable.h"
class Tablet : public Portable
{
private:
    int detachableKeyboard;

public:
    Tablet(int detachKeyboard, int batteryCapacitymAh,
           int hasSIM, char *model,
           char *manufactorer,
           int ram, int storage) : Portable(batteryCapacitymAh, hasSIM, model, manufactorer, ram, storage)
    {
        this->detachableKeyboard = detachKeyboard;
    }
    Tablet() : Portable()
    {
        detachableKeyboard = -1;
    }
    Tablet(const Tablet &other) : Portable(other)
    {
        detachableKeyboard = other.detachableKeyboard;
    }
    virtual ~Tablet() = default;
    int getDetachableKeyboard();
    void setDetachableKeyboard(int detachableKeyboard);
    void printHead() override;
    virtual void editParametersMenu() override;
    Tablet &operator=(const Tablet &other);
    bool operator==(const Tablet &other);
    friend std::ostream &operator<<(std::ostream &os, Tablet &t);
    friend std::istream &operator>>(std::istream &is, Tablet &t);
};

#endif
