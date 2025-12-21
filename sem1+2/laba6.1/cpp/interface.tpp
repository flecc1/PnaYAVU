#include "../headers/interface.h"
#include "../headers/ochered.h"
#include "../headers/human.h"
#include "../headers/student.h"
#include "../headers/komis.h"
#include "../headers/prepod_komis.h"
#include "error.cpp"
// file exception
#include "../headers/file_exception.h"

template<class T>
void Interface<T>::menu()
{
    int choice;
    Exp_vvoda validator;
    
    do
    {
        Interface<Human> humanobj;
        Interface<Student> studentobj;
        Interface<Komisia> komisobj;
        Interface<Prepod> prepodobj;
        Interface<Prepod_Komis> prepod_komisobj;

        cout << "1. Работа с людьми" << endl;
        cout << "2. Работа с студентами" << endl;
        cout << "3. Работа с комиссией" << endl;
        cout << "4. Работа с преподами" << endl;
        cout << "5. Работа с преподавателями членами комиссии" << endl;
        cout << "0. Выход" << std::endl;

        choice = validator.inputNumber(cin, 0, 5);
            
        switch (choice)
        {
            case 0:
                break;
            case 1:
                humanobj.fun();
                break;
            case 2:
                studentobj.fun();
                break;
            case 3:
                komisobj.fun();
                break;
            case 4:
                prepodobj.fun();
                break;
            case 5:
                prepod_komisobj.fun();
                break;
        }
    } while (choice != 0);
}

template<class T>
void Interface<T>::sortByAge()
{
    och.sortByAge();
}

template <class T>
void Interface<T>::editobj(T& object)
{
    object.edit();
}

template <class T>
void Interface<T>::fun()
{
    int choice;
    Exp_vvoda validator;
    
    do
    {
        cout << endl;
        cout << "1. Добавить объект" << endl;
        cout << "2. Показать все объекты" << endl;
        cout << "3. Редактирование параметров" << endl;
        cout << "4. Удалить объект" << endl;
        cout << "5. Сортировка" << endl;
        cout << "6. Очистить список" << endl;
        cout << "7. Показать размер списка" << endl;
        cout << "8. Поиск" << endl;
        cout << "9. Сохранить в текстовый файл" << endl;
        cout << "10. Сохранить в бинарный файл" << endl;
        cout << "11. Загрузить из текстового файла" << endl;
        cout << "12. Загрузить из бинарного файла" << endl;
        cout << "13. Показать содержимое файла" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите действие: ";

        choice = validator.inputNumber(cin, 0, 13);
        cin.ignore();
        
        switch (choice)
        {
        case 1:
        {
            T obj;
            try {
                cin >> obj;  
                och.pushback(obj);
                cout << "Объект добавлен!" << endl;
            } catch (const My_exception& e) {
                cout << "Ошибка при добавлении: ";
                e.printError();
            }
            break;
        }
        case 2:
        {
            if (och.is_empty()) 
            {
                cout << "Список пуст!" << endl;
            } 
            else 
            {
                cout << "\n=== СПИСОК ОБЪЕКТОВ ===" << endl;
                T temp;
                temp.printHeader();
                cout << och << endl;
            }
            break;
        }
        case 3:
        {
            if (och.is_empty()) 
            {
                cout << "Нет объектов для редактирования!" << endl;
                break;
            }
            
            cout << "\nТекущий список:" << endl;
            T temp;
            temp.printHeader();
            cout << och << endl;
            
            int index;
            cout << "Введите индекс для редактирования (1-" << och.getSize() << "): ";
            index = validator.inputNumber(cin, 1, och.getSize());
            
            try {
                och[index - 1].edit();
                cout << "Объект отредактирован!" << endl;
            } catch (const My_exception& e) {
                cout << "Ошибка при редактировании: ";
                e.printError();
            }
            break;
        }
        case 4:
        {
            if (och.is_empty()) 
            {
                cout << "Список пуст!" << endl;
                break;
            }
            
            cout << "\nТекущий список:" << endl;
            T temp;
            temp.printHeader();
            cout << och << endl;
            
            int index;
            cout << "Введите индекс для удаления (1-" << och.getSize() << "): ";
            index = validator.inputNumber(cin, 1, och.getSize());
            
            if (och.remove_by_index(index - 1)) {
                cout << "Объект удален!" << endl;
            } else {
                cout << "Ошибка при удалении!" << endl;
            }
            break;
        }
        case 5:
        {
            if (och.is_empty()) 
            {
                cout << "Список пуст!" << endl;
            }
            else
            {
                och.sortByAge();
                cout << "Список отсортирован!" << endl;
            }
            break;
        }
        case 6:
        {
            och.free();
            cout << "Список очищен!" << endl;
            break;
        }
        case 7:
        {
            cout << "Размер списка: " << och.getSize() << " элементов" << endl;
            break;
        }
        case 8:
        {
            T value;
            cout << "Enter parametrs" << endl;
            value.edit();
            Ochered<T> findResult = och.findAllWithParameters(value);
            if (!findResult.is_empty())
            {
                findResult[0].printHeader();
                cout << findResult;
            }
            else
                cout << "No elements found" << endl;
            break;
        }
        case 9:  // Сохранить в текстовый файл
        {
            string filename;
            cout << "\n=== СОХРАНЕНИЕ В ТЕКСТОВЫЙ ФАЙЛ ===" << endl;
            cout << "Введите имя файла (например: data.txt): ";
            getline(cin, filename);
            if (!filename.empty()) {
                try {
                    File_txt<T> file(filename);
                    file.write(och);
                    cout << "✓ Данные успешно сохранены в текстовый файл!" << endl;
                } catch (const File_exception& e) {
                    cout << "✗ Ошибка при сохранении в текстовый файл: ";
                    e.printError();
                }
            }
            break;
        }
        case 10:  // Сохранить в бинарный файл
        {
            string filename;
            cout << "\n=== СОХРАНЕНИЕ В БИНАРНЫЙ ФАЙЛ ===" << endl;
            cout << "Введите имя файла (например: data.bin): ";
            getline(cin, filename);
            if (!filename.empty()) {
                try {
                    File_bin<T> file(filename);
                    file.write(och);
                    cout << "✓ Данные успешно сохранены в бинарный файл!" << endl;
                } catch (const File_exception& e) {
                    cout << "✗ Ошибка при сохранении в бинарный файл: ";
                    e.printError();
                }
            }
            break;
        }
        case 11:  // Загрузить из текстового файла
        {
            string filename;
            cout << "\n=== ЗАГРУЗКА ИЗ ТЕКСТОВОГО ФАЙЛА ===" << endl;
            cout << "Внимание: текущие данные будут заменены!" << endl;
            cout << "Введите имя файла (например: data.txt): ";
            getline(cin, filename);
            if (!filename.empty()) {
                try {
                    File_txt<T> file(filename);
                    och = file.read();
                    cout << "✓ Загружено " << och.getSize() << " объектов из текстового файла" << endl;
                } catch (const File_exception& e) {
                    cout << "✗ Ошибка при загрузке из текстового файла: ";
                    e.printError();
                }
            }
            break;
        }
        case 12:  // Загрузить из бинарного файла
        {
            string filename;
            cout << "\n=== ЗАГРУЗКА ИЗ БИНАРНОГО ФАЙЛА ===" << endl;
            cout << "Внимание: текущие данные будут заменены!" << endl;
            cout << "Введите имя файла (например: data.bin): ";
            getline(cin, filename);
            if (!filename.empty()) {
                try {
                    File_bin<T> file(filename);
                    och = file.read();
                    cout << "✓ Загружено " << och.getSize() << " объектов из бинарного файла" << endl;
                } catch (const File_exception& e) {
                    cout << "✗ Ошибка при загрузке из бинарного файла: ";
                    e.printError();
                }
            }
            break;
        }
        case 13:  // Показать содержимое файла
        {
            string filename;
            cout << "\n=== ПРОСМОТР СОДЕРЖИМОГО ФАЙЛА ===" << endl;
            cout << "Введите имя файла: ";
            getline(cin, filename);
                if (!filename.empty()) {
                try {
                    File_txt<T> file(filename);
                    file.display();
                } catch (...) {
                    try {
                        File_bin<T> file(filename);
                        file.display();
                    } catch (const File_exception& e) {
                        cout << "✗ Ошибка при открытии файла: ";
                        e.printError();
                    }
                }
            }
            break;
        }
        case 0:
            break;
        }
    } while (choice != 0);
}