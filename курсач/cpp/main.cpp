#include "../headers/interface.h"
#include "../headers/LibraryItem.h"
#include "../headers/Book.h"
#include "../headers/AudioMaterial.h"
#include "../headers/AudioBook.h"
#include "../headers/StandardBook.h"
#include "../headers/EducationalAudio.h"
#include "../headers/ResearchPaper.h"
#include "../headers/excep_vvoda.h"
#include <iostream>

using namespace std;
int restart();
int main() 
{
    Interface<LibraryItem> app;
    int again = 1;
    
    cout << "========================================" << endl;
    cout << "   СИСТЕМА УПРАВЛЕНИЯ БИБЛИОТЕКОЙ" << endl;
    cout << "========================================" << endl;
    
    while (again)
    {
        try {
            app.menu();
            again = restart();
        } catch (const My_exception& e) {
            cout << "\n✗ Критическая ошибка: ";
            e.printError();
            cout << "Программа будет завершена." << endl;
            again = 0;
        } catch (const exception& e) {
            cout << "\n✗ Неожиданная ошибка: " << e.what() << endl;
            cout << "Программа будет завершена." << endl;
            again = 0;
        } catch (...) {
            cout << "\n✗ Неизвестная ошибка!" << endl;
            cout << "Программа будет завершена." << endl;
            again = 0;
        }
    }
    
    cout << "\n========================================" << endl;
    cout << "   Программа завершена." << endl;
    cout << "========================================" << endl;
    return 0;
}

