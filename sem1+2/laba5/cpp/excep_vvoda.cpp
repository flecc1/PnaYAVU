#include "../headers/excep_vvoda.h"

    void Exp_vvoda::printError()const
    {
        cout << "Ошибка ввода [" << error_type << "] " << error_code << ":\n" << message << endl;
    }