#include <iostream>
#include "../headers/excep_vvoda.h"
using namespace std;

int restart()
{
    int again;
    cout << "\nСнова? Да - 1. Нет - 0:\t";
    
    // Создаем объект исключения для использования методов
    Exp_vvoda validator;
    again = validator.inputNumber(cin, 0, 1);
    return again;
}