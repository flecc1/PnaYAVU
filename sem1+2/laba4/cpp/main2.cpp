#include "../headers/interface.h"

int main() {
    Interface app;
    int again = 1;
    
    while (again) 
    {
        app.main_menu();
        again = app.restart();
    }
    
    cout << "Программа завершена." << endl;
    return 0;
}