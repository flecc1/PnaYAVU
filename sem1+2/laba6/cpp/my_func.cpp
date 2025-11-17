#include <iostream>
#include "../headers/excep_vvoda.h"
using namespace std;

int restart()
{
    int again;
    cout << "\nСнова? Да - 1. Нет - 0:\t";
    
    // Создаем объект исключения для использования методов
    My_exception validator;
    again = validator.inputNumber(0, 1);
    return again;
}