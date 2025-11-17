#include <iostream>
#include "error.cpp"
using namespace std;

int restart()
{
    int again;
    cout << "\nСнова? Да - 1. Нет - 0:\t";
    
    try {
        again = inputNumber(0, 1);
        return again;
    } catch (Exp_vvoda& e) {
        cout << "Ошибка. Переход к завершению...";
        return 0;
    }
}