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

/**
 * @brief Функция для повторного запуска программы
 * @return 1 если пользователь хочет продолжить, 0 если выйти
 */
int restart()
{
    int again;
    cout << "\nСнова? Да - 1. Нет - 0:\t";
    
    // Создаем объект исключения для использования методов
    Exp_vvoda validator;
    again = validator.inputNumber(cin, 0, 1);
    return again;
}

/**
 * @brief Главная функция программы
 * @return Код завершения программы
 */
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

