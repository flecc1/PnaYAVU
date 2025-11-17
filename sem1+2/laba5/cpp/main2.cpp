#include "../headers/interface.h"


int restart();
int main() 
{
    Interface<Human> app;
    int again = 1;
    int m;
    while (again)
    {
        app.menu();
        again = restart();
    }
    
    cout << "Программа завершена." << endl;
    return 0;
}