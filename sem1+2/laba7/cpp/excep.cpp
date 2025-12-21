#include "../headers/excep.h"

void My_exception::printError() const
{
    cout << "Ошибка " << error_code << ": " << message << endl;
}


