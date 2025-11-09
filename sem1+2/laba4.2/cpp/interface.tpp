#include "../headers/interface.h"
#include "../headers/ochered.h"
#include "../headers/human.h"
#include "../headers/student.h"
#include "../headers/komis.h"
#include "../headers/prepod_komis.h"



template<class T>
void Interface<T>::menu()
{
    int choice;
    do
    {
        Interface<Human> humanobj;
        Interface<Student> studentobj;
        Interface<Komisia> komisobj;
        Interface<Prepod> prepodobj;
        Interface<Prepod_Komis> prepod_komisobj;

        cout << "1. Работа с людьми" << endl;
        cout << "2. Работа с студентами" << endl;
        cout << "3. Работа с комисией" << endl;
        cout << "4. Работа с преподами" << endl;
        cout << "5. Работа с преподователями членами комисии" << endl;
        cout << "0. Выход" << std::endl;

        cin >> choice;
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
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
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
    do
    {
        system("cls");
        cout << "=========================================" << endl;
        cout << "1. Добавить объект" << endl;
        cout << "2. Показать все объекты" << endl;
        cout << "3. Редактирование параметров" << endl;
        cout << "4. Удалить объект" << endl;
        cout << "5. Сортировка" << endl;
        cout << "6. Очистить список" << endl;
        cout << "7. Показать размер списка" << endl;
        cout << "0. Назад" << endl;
        cout << "=========================================" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            T obj;
            cin >> obj;
            och.pushback(obj);
            cout << "Объект добавлен!" << endl;
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
            cin >> index;
            
            if (index >= 1 && index <= och.getSize())
            {
                och[index - 1].edit();
                cout << "Объект отредактирован!" << endl;
            }
            else
            {
                cout << "Неверный индекс!" << endl;
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
            cin >> index;
            
            if (index >= 1 && index <= och.getSize())
            {
                och.remove_by_index(index - 1);
                cout << "Объект удален!" << endl;
            }
            else
            {
                cout << "Неверный индекс!" << endl;
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
        case 0:
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);
}