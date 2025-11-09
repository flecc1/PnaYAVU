#ifndef MENU_H
#define MENU_H

#include "./headers/student.h"
#include "./headers/prepod.h"
#include "./headers/komis.h"
#include "./headers/prepod_komis.h"
#include "./headers/human.h"
#include "./headers/ochered.h"
#include <iostream>
using namespace std;

void editHuman(Human& obj) {
    int fieldChoice;
    do {
        cout << "\n=== РЕДАКТИРОВАНИЕ HUMAN ===" << endl;
        cout << "Текущий объект:" << endl;
        obj.printHeader();
        cout << obj << endl;
        
        cout << "\nВыберите поле для изменения:" << endl;
        cout << "1. Имя" << endl;
        cout << "2. Фамилия" << endl;
        cout << "3. Возраст" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите поле: ";
        cin >> fieldChoice;
        
        switch(fieldChoice) {
            case 1: {
                char newName[N];
                cout << "Введите новое имя: ";
                cin >> newName;
                obj.set_name(newName);
                cout << "Имя изменено!" << endl;
                break;
            }
            case 2: {
                char newSurname[N];
                cout << "Введите новую фамилию: ";
                cin >> newSurname;
                obj.set_second_name(newSurname);
                cout << "Фамилия изменена!" << endl;
                break;
            }
            case 3: {
                int newAge;
                cout << "Введите новый возраст: ";
                cin >> newAge;
                obj.set_age(newAge);
                cout << "Возраст изменен!" << endl;
                break;
            }
            case 0:
                cout << "Выход из редактора..." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (fieldChoice != 0);
}

void editStudent(Student& obj) {
    int fieldChoice;
    do {
        cout << "\n=== РЕДАКТИРОВАНИЕ STUDENT ===" << endl;
        cout << "Текущий объект:" << endl;
        obj.printHeader();
        cout << obj << endl;
        
        cout << "\nВыберите поле для изменения:" << endl;
        cout << "1. Имя" << endl;
        cout << "2. Фамилия" << endl;
        cout << "3. Возраст" << endl;
        cout << "4. Средний балл" << endl;
        cout << "5. Стипендия" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите поле: ";
        cin >> fieldChoice;
        
        switch(fieldChoice) {
            case 1: {
                char newName[N];
                cout << "Введите новое имя: ";
                cin >> newName;
                obj.set_name(newName);
                cout << "Имя изменено!" << endl;
                break;
            }
            case 2: {
                char newSurname[N];
                cout << "Введите новую фамилию: ";
                cin >> newSurname;
                obj.set_second_name(newSurname);
                cout << "Фамилия изменена!" << endl;
                break;
            }
            case 3: {
                int newAge;
                cout << "Введите новый возраст: ";
                cin >> newAge;
                obj.set_age(newAge);
                cout << "Возраст изменен!" << endl;
                break;
            }
            case 4: {
                double newBal;
                cout << "Введите новый средний балл: ";
                cin >> newBal;
                obj.set_sr_bal(newBal);
                cout << "Средний балл изменен!" << endl;
                break;
            }
            case 5: {
                int newStep;
                cout << "Введите новую стипендию: ";
                cin >> newStep;
                obj.set_stependiya(newStep);
                cout << "Стипендия изменена!" << endl;
                break;
            }
            case 0:
                cout << "Выход из редактора..." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (fieldChoice != 0);
}

void editPrepod(Prepod& obj) {
    int fieldChoice;
    do {
        cout << "\n=== РЕДАКТИРОВАНИЕ PREPOD ===" << endl;
        cout << "Текущий объект:" << endl;
        obj.printHeader();
        cout << obj << endl;
        
        cout << "\nВыберите поле для изменения:" << endl;
        cout << "1. Имя" << endl;
        cout << "2. Фамилия" << endl;
        cout << "3. Возраст" << endl;
        cout << "4. Должность" << endl;
        cout << "5. Специальность" << endl;
        cout << "6. Список трудов" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите поле: ";
        cin >> fieldChoice;
        
        switch(fieldChoice) {
            case 1: {
                char newName[N];
                cout << "Введите новое имя: ";
                cin >> newName;
                obj.set_name(newName);
                cout << "Имя изменено!" << endl;
                break;
            }
            case 2: {
                char newSurname[N];
                cout << "Введите новую фамилию: ";
                cin >> newSurname;
                obj.set_second_name(newSurname);
                cout << "Фамилия изменена!" << endl;
                break;
            }
            case 3: {
                int newAge;
                cout << "Введите новый возраст: ";
                cin >> newAge;
                obj.set_age(newAge);
                cout << "Возраст изменен!" << endl;
                break;
            }
            case 4: {
                char newDolgnost[M];
                cout << "Введите новую должность: ";
                cin >> newDolgnost;
                obj.set_dolgnost(newDolgnost);
                cout << "Должность изменена!" << endl;
                break;
            }
            case 5: {
                char newSpec[M];
                cout << "Введите новую специальность: ";
                cin >> newSpec;
                obj.set_specialnost(newSpec);
                cout << "Специальность изменена!" << endl;
                break;
            }
            case 6: {
                char newTruds[M];
                cout << "Введите новый список трудов: ";
                cin >> newTruds;
                obj.set_truds(newTruds);
                cout << "Список трудов изменен!" << endl;
                break;
            }
            case 0:
                cout << "Выход из редактора..." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (fieldChoice != 0);
}

void editKomisia(Komisia& obj) {
    int fieldChoice;
    do {
        cout << "\n=== РЕДАКТИРОВАНИЕ KOMISIA ===" << endl;
        cout << "Текущий объект:" << endl;
        obj.printHeader();
        cout << obj << endl;
        
        cout << "\nВыберите поле для изменения:" << endl;
        cout << "1. Имя" << endl;
        cout << "2. Фамилия" << endl;
        cout << "3. Возраст" << endl;
        cout << "4. Название комиссии" << endl;
        cout << "5. Автобиография" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите поле: ";
        cin >> fieldChoice;
        
        switch(fieldChoice) {
            case 1: {
                char newName[N];
                cout << "Введите новое имя: ";
                cin >> newName;
                obj.set_name(newName);
                cout << "Имя изменено!" << endl;
                break;
            }
            case 2: {
                char newSurname[N];
                cout << "Введите новую фамилию: ";
                cin >> newSurname;
                obj.set_second_name(newSurname);
                cout << "Фамилия изменена!" << endl;
                break;
            }
            case 3: {
                int newAge;
                cout << "Введите новый возраст: ";
                cin >> newAge;
                obj.set_age(newAge);
                cout << "Возраст изменен!" << endl;
                break;
            }
            case 4: {
                char newKomis[M];
                cout << "Введите новое название комиссии: ";
                cin >> newKomis;
                obj.set_komis_name(newKomis);
                cout << "Название комиссии изменено!" << endl;
                break;
            }
            case 5: {
                char newBio[M];
                cout << "Введите новую автобиографию: ";
                cin >> newBio;
                obj.set_autobio(newBio);
                cout << "Автобиография изменена!" << endl;
                break;
            }
            case 0:
                cout << "Выход из редактора..." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (fieldChoice != 0);
}

void editPrepod_Komis(Prepod_Komis& obj) {
    int fieldChoice;
    do {
        cout << "\n=== РЕДАКТИРОВАНИЕ PREPOD_KOMIS ===" << endl;
        cout << "Текущий объект:" << endl;
        obj.printHeader();
        cout << obj << endl;
        
        cout << "\nВыберите поле для изменения:" << endl;
        cout << "1. Имя" << endl;
        cout << "2. Фамилия" << endl;
        cout << "3. Возраст" << endl;
        cout << "4. Должность" << endl;
        cout << "5. Специальность" << endl;
        cout << "6. Список трудов" << endl;
        cout << "7. Название комиссии" << endl;
        cout << "8. Автобиография" << endl;
        cout << "9. Список работ" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите поле: ";
        cin >> fieldChoice;
        
        switch(fieldChoice) {
            case 1: {
                char newName[N];
                cout << "Введите новое имя: ";
                cin >> newName;
                obj.set_name(newName);
                cout << "Имя изменено!" << endl;
                break;
            }
            case 2: {
                char newSurname[N];
                cout << "Введите новую фамилию: ";
                cin >> newSurname;
                obj.set_second_name(newSurname);
                cout << "Фамилия изменена!" << endl;
                break;
            }
            case 3: {
                int newAge;
                cout << "Введите новый возраст: ";
                cin >> newAge;
                obj.set_age(newAge);
                cout << "Возраст изменен!" << endl;
                break;
            }
            case 4: {
                char newDolgnost[M];
                cout << "Введите новую должность: ";
                cin >> newDolgnost;
                obj.set_dolgnost(newDolgnost);
                cout << "Должность изменена!" << endl;
                break;
            }
            case 5: {
                char newSpec[M];
                cout << "Введите новую специальность: ";
                cin >> newSpec;
                obj.set_specialnost(newSpec);
                cout << "Специальность изменена!" << endl;
                break;
            }
            case 6: {
                char newTruds[M];
                cout << "Введите новый список трудов: ";
                cin >> newTruds;
                obj.set_truds(newTruds);
                cout << "Список трудов изменен!" << endl;
                break;
            }
            case 7: {
                char newKomis[M];
                cout << "Введите новое название комиссии: ";
                cin >> newKomis;
                obj.set_komis_name(newKomis);
                cout << "Название комиссии изменено!" << endl;
                break;
            }
            case 8: {
                char newBio[M];
                cout << "Введите новую автобиографию: ";
                cin >> newBio;
                obj.set_autobio(newBio);
                cout << "Автобиография изменена!" << endl;
                break;
            }
            case 9: {
                char newRaboty[M];
                cout << "Введите новый список работ: ";
                cin >> newRaboty;
                obj.set_spisok_rabot(newRaboty);
                cout << "Список работ изменен!" << endl;
                break;
            }
            case 0:
                cout << "Выход из редактора..." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (fieldChoice != 0);
}

template<class T>
void menu() {
    Ochered<T> list;
    int choice;
    
    do {
        cout << "\n=== МЕНЮ РАБОТЫ С ДАННЫМИ ===" << endl;
        cout << "1. Добавить элемент" << endl;
        cout << "2. Удалить элемент по индексу" << endl;
        cout << "3. Вывести все данные" << endl;
        cout << "4. Очистить список" << endl;
        cout << "5. Показать размер списка" << endl;
        cout << "6. Отсортировать по возрасту" << endl;
        cout << "0. Выход в главное меню" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                T obj;
                cin >> obj;
                list.pushback(obj);
                cout << "Элемент добавлен!" << endl;
                break;
            }
            case 2: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                    break;
                }
                
                cout << "\nТекущий список:" << endl;
                T temp;
                temp.printHeader();
                cout << list << endl;
                
                int index;
                cout << "Введите индекс для удаления (1-" << list.getSize() << "): ";
                cin >> index;
                
                if (list.remove_by_index(index - 1)) {
                    cout << "Элемент удален!" << endl;
                } else {
                    cout << "Неверный индекс!" << endl;
                }
                break;
            }
            case 3: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    cout << "\n=== ДАННЫЕ ===" << endl;
                    T temp;
                    temp.printHeader();
                    cout << list << endl;
                }
                break;
            }
            case 4: {
                list.free();
                cout << "Список очищен!" << endl;
                break;
            }
            case 5: {
                cout << "Размер списка: " << list.getSize() << " элементов" << endl;
                break;
            }
            case 6: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    list.sortByAge();
                    cout << "Список отсортирован по возрасту!" << endl;
                }
                break;
            }
            case 0: {
                cout << "Выход в главное меню..." << endl;
                break;
            }
            default: {
                cout << "Неверный выбор!" << endl;
                break;
            }
        }
    } while (choice != 0);
}


template<>
void menu<Human>() {
    Ochered<Human> list;
    int choice;
    
    do {
        cout << "\n=== МЕНЮ РАБОТЫ С HUMAN ===" << endl;
        cout << "1. Добавить Human" << endl;
        cout << "2. Удалить Human по индексу" << endl;
        cout << "3. Вывести все Human" << endl;
        cout << "4. Очистить список" << endl;
        cout << "5. Показать размер списка" << endl;
        cout << "6. Отсортировать по возрасту" << endl;
        cout << "7. Редактировать Human" << endl;
        cout << "0. Выход в главное меню" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                Human obj;
                cin >> obj;
                list.pushback(obj);
                cout << "Human добавлен!" << endl;
                break;
            }
            case 2: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                    break;
                }
                
                cout << "\nТекущий список:" << endl;
                Human temp;
                temp.printHeader();
                cout << list << endl;
                
                int index;
                cout << "Введите индекс для удаления (1-" << list.getSize() << "): ";
                cin >> index;
                
                if (list.remove_by_index(index - 1)) {
                    cout << "Human удален!" << endl;
                } else {
                    cout << "Неверный индекс!" << endl;
                }
                break;
            }
            case 3: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    cout << "\n=== HUMAN ===" << endl;
                    Human temp;
                    temp.printHeader();
                    cout << list << endl;
                }
                break;
            }
            case 4: {
                list.free();
                cout << "Список очищен!" << endl;
                break;
            }
            case 5: {
                cout << "Размер списка: " << list.getSize() << " элементов" << endl;
                break;
            }
            case 6: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    list.sortByAge();
                    cout << "Список отсортирован по возрасту!" << endl;
                }
                break;
            }
            case 7: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                    break;
                }
                
                cout << "\nТекущий список:" << endl;
                Human temp;
                temp.printHeader();
                cout << list << endl;
                
                int index;
                cout << "Введите индекс Human для редактирования (1-" << list.getSize() << "): ";
                cin >> index;
                
                if (index < 1 || index > list.getSize()) {
                    cout << "Неверный индекс!" << endl;
                } else {
                    editHuman(list[index - 1]);
                    cout << "Human обновлен!" << endl;
                }
                break;
            }
            case 0: {
                cout << "Выход в главное меню..." << endl;
                break;
            }
            default: {
                cout << "Неверный выбор!" << endl;
                break;
            }
        }
    } while (choice != 0);
}

template<>
void menu<Student>() {
    Ochered<Student> list;
    int choice;
    
    do {
        cout << "\n=== МЕНЮ РАБОТЫ С STUDENT ===" << endl;
        cout << "1. Добавить Student" << endl;
        cout << "2. Удалить Student по индексу" << endl;
        cout << "3. Вывести все Student" << endl;
        cout << "4. Очистить список" << endl;
        cout << "5. Показать размер списка" << endl;
        cout << "6. Отсортировать по возрасту" << endl;
        cout << "7. Редактировать Student" << endl;
        cout << "0. Выход в главное меню" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                Student obj;
                cin >> obj;
                list.pushback(obj);
                cout << "Student добавлен!" << endl;
                break;
            }
            case 2: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                    break;
                }
                
                cout << "\nТекущий список:" << endl;
                Student temp;
                temp.printHeader();
                cout << list << endl;
                
                int index;
                cout << "Введите индекс для удаления (1-" << list.getSize() << "): ";
                cin >> index;
                
                if (list.remove_by_index(index - 1)) {
                    cout << "Student удален!" << endl;
                } else {
                    cout << "Неверный индекс!" << endl;
                }
                break;
            }
            case 3: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    cout << "\n=== STUDENT ===" << endl;
                    Student temp;
                    temp.printHeader();
                    cout << list << endl;
                }
                break;
            }
            case 4: {
                list.free();
                cout << "Список очищен!" << endl;
                break;
            }
            case 5: {
                cout << "Размер списка: " << list.getSize() << " элементов" << endl;
                break;
            }
            case 6: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    list.sortByAge();
                    cout << "Список отсортирован по возрасту!" << endl;
                }
                break;
            }
            case 7: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                    break;
                }
                
                cout << "\nТекущий список:" << endl;
                Student temp;
                temp.printHeader();
                cout << list << endl;
                
                int index;
                cout << "Введите индекс Student для редактирования (1-" << list.getSize() << "): ";
                cin >> index;
                
                if (index < 1 || index > list.getSize()) {
                    cout << "Неверный индекс!" << endl;
                } else {
                    editStudent(list[index - 1]);
                    cout << "Student обновлен!" << endl;
                }
                break;
            }
            case 0: {
                cout << "Выход в главное меню..." << endl;
                break;
            }
            default: {
                cout << "Неверный выбор!" << endl;
                break;
            }
        }
    } while (choice != 0);
}

// Специализация для Prepod
template<>
void menu<Prepod>() {
    Ochered<Prepod> list;
    int choice;
    
    do {
        cout << "\n=== МЕНЮ РАБОТЫ С PREPOD ===" << endl;
        cout << "1. Добавить Prepod" << endl;
        cout << "2. Удалить Prepod по индексу" << endl;
        cout << "3. Вывести все Prepod" << endl;
        cout << "4. Очистить список" << endl;
        cout << "5. Показать размер списка" << endl;
        cout << "6. Отсортировать по возрасту" << endl;
        cout << "7. Редактировать Prepod" << endl;
        cout << "0. Выход в главное меню" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                Prepod obj;
                cin >> obj;
                list.pushback(obj);
                cout << "Prepod добавлен!" << endl;
                break;
            }
            case 2: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                    break;
                }
                
                cout << "\nТекущий список:" << endl;
                Prepod temp;
                temp.printHeader();
                cout << list << endl;
                
                int index;
                cout << "Введите индекс для удаления (1-" << list.getSize() << "): ";
                cin >> index;
                
                if (list.remove_by_index(index - 1)) {
                    cout << "Prepod удален!" << endl;
                } else {
                    cout << "Неверный индекс!" << endl;
                }
                break;
            }
            case 3: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    cout << "\n=== PREPOD ===" << endl;
                    Prepod temp;
                    temp.printHeader();
                    cout << list << endl;
                }
                break;
            }
            case 4: {
                list.free();
                cout << "Список очищен!" << endl;
                break;
            }
            case 5: {
                cout << "Размер списка: " << list.getSize() << " элементов" << endl;
                break;
            }
            case 6: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    list.sortByAge();
                    cout << "Список отсортирован по возрасту!" << endl;
                }
                break;
            }
            case 7: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                    break;
                }
                
                cout << "\nТекущий список:" << endl;
                Prepod temp;
                temp.printHeader();
                cout << list << endl;
                
                int index;
                cout << "Введите индекс Prepod для редактирования (1-" << list.getSize() << "): ";
                cin >> index;
                
                if (index < 1 || index > list.getSize()) {
                    cout << "Неверный индекс!" << endl;
                } else {
                    editPrepod(list[index - 1]);
                    cout << "Prepod обновлен!" << endl;
                }
                break;
            }
            case 0: {
                cout << "Выход в главное меню..." << endl;
                break;
            }
            default: {
                cout << "Неверный выбор!" << endl;
                break;
            }
        }
    } while (choice != 0);
}

// Специализация для Komisia
template<>
void menu<Komisia>() {
    Ochered<Komisia> list;
    int choice;
    
    do {
        cout << "\n=== МЕНЮ РАБОТЫ С KOMISIA ===" << endl;
        cout << "1. Добавить Komisia" << endl;
        cout << "2. Удалить Komisia по индексу" << endl;
        cout << "3. Вывести все Komisia" << endl;
        cout << "4. Очистить список" << endl;
        cout << "5. Показать размер списка" << endl;
        cout << "6. Отсортировать по возрасту" << endl;
        cout << "7. Редактировать Komisia" << endl;
        cout << "0. Выход в главное меню" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                Komisia obj;
                cin >> obj;
                list.pushback(obj);
                cout << "Komisia добавлена!" << endl;
                break;
            }
            case 2: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                    break;
                }
                
                cout << "\nТекущий список:" << endl;
                Komisia temp;
                temp.printHeader();
                cout << list << endl;
                
                int index;
                cout << "Введите индекс для удаления (1-" << list.getSize() << "): ";
                cin >> index;
                
                if (list.remove_by_index(index - 1)) {
                    cout << "Komisia удалена!" << endl;
                } else {
                    cout << "Неверный индекс!" << endl;
                }
                break;
            }
            case 3: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    cout << "\n=== KOMISIA ===" << endl;
                    Komisia temp;
                    temp.printHeader();
                    cout << list << endl;
                }
                break;
            }
            case 4: {
                list.free();
                cout << "Список очищен!" << endl;
                break;
            }
            case 5: {
                cout << "Размер списка: " << list.getSize() << " элементов" << endl;
                break;
            }
            case 6: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    list.sortByAge();
                    cout << "Список отсортирован по возрасту!" << endl;
                }
                break;
            }
            case 7: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                    break;
                }
                
                cout << "\nТекущий список:" << endl;
                Komisia temp;
                temp.printHeader();
                cout << list << endl;
                
                int index;
                cout << "Введите индекс Komisia для редактирования (1-" << list.getSize() << "): ";
                cin >> index;
                
                if (index < 1 || index > list.getSize()) {
                    cout << "Неверный индекс!" << endl;
                } else {
                    editKomisia(list[index - 1]);
                    cout << "Komisia обновлена!" << endl;
                }
                break;
            }
            case 0: {
                cout << "Выход в главное меню..." << endl;
                break;
            }
            default: {
                cout << "Неверный выбор!" << endl;
                break;
            }
        }
    } while (choice != 0);
}

// Специализация для Prepod_Komis
template<>
void menu<Prepod_Komis>() {
    Ochered<Prepod_Komis> list;
    int choice;
    
    do {
        cout << "\n=== МЕНЮ РАБОТЫ С PREPOD_KOMIS ===" << endl;
        cout << "1. Добавить Prepod_Komis" << endl;
        cout << "2. Удалить Prepod_Komis по индексу" << endl;
        cout << "3. Вывести все Prepod_Komis" << endl;
        cout << "4. Очистить список" << endl;
        cout << "5. Показать размер списка" << endl;
        cout << "6. Отсортировать по возрасту" << endl;
        cout << "7. Редактировать Prepod_Komis" << endl;
        cout << "0. Выход в главное меню" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                Prepod_Komis obj;
                cin >> obj;
                list.pushback(obj);
                cout << "Prepod_Komis добавлен!" << endl;
                break;
            }
            case 2: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                    break;
                }
                
                cout << "\nТекущий список:" << endl;
                Prepod_Komis temp;
                temp.printHeader();
                cout << list << endl;
                
                int index;
                cout << "Введите индекс для удаления (1-" << list.getSize() << "): ";
                cin >> index;
                
                if (list.remove_by_index(index - 1)) {
                    cout << "Prepod_Komis удален!" << endl;
                } else {
                    cout << "Неверный индекс!" << endl;
                }
                break;
            }
            case 3: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    cout << "\n=== PREPOD_KOMIS ===" << endl;
                    Prepod_Komis temp;
                    temp.printHeader();
                    cout << list << endl;
                }
                break;
            }
            case 4: {
                list.free();
                cout << "Список очищен!" << endl;
                break;
            }
            case 5: {
                cout << "Размер списка: " << list.getSize() << " элементов" << endl;
                break;
            }
            case 6: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    list.sortByAge();
                    cout << "Список отсортирован по возрасту!" << endl;
                }
                break;
            }
            case 7: {
                if (list.is_empty()) {
                    cout << "Список пуст!" << endl;
                    break;
                }
                
                cout << "\nТекущий список:" << endl;
                Prepod_Komis temp;
                temp.printHeader();
                cout << list << endl;
                
                int index;
                cout << "Введите индекс Prepod_Komis для редактирования (1-" << list.getSize() << "): ";
                cin >> index;
                
                if (index < 1 || index > list.getSize()) {
                    cout << "Неверный индекс!" << endl;
                } else {
                    editPrepod_Komis(list[index - 1]);
                    cout << "Prepod_Komis обновлен!" << endl;
                }
                break;
            }
            case 0: {
                cout << "Выход в главное меню..." << endl;
                break;
            }
            default: {
                cout << "Неверный выбор!" << endl;
                break;
            }
        }
    } while (choice != 0);
}

void mainMenu() {
    int choice;
    
    do {
        cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << endl;
        cout << "1. Работа с Human" << endl;
        cout << "2. Работа с Student" << endl;
        cout << "3. Работа с Prepod" << endl;
        cout << "4. Работа с Komisia" << endl;
        cout << "5. Работа с Prepod_Komis" << endl;
        cout << "0. Выход из программы" << endl;
        cout << "Выберите тип данных: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\n--- РАБОТА С HUMAN ---" << endl;
                menu<Human>();
                break;
            case 2:
                cout << "\n--- РАБОТА С STUDENT ---" << endl;
                menu<Student>();
                break;
            case 3:
                cout << "\n--- РАБОТА С PREPOD ---" << endl;
                menu<Prepod>();
                break;
            case 4:
                cout << "\n--- РАБОТА С KOMISIA ---" << endl;
                menu<Komisia>();
                break;
            case 5:
                cout << "\n--- РАБОТА С PREPOD_KOMIS ---" << endl;
                menu<Prepod_Komis>();
                break;
            case 0:
                cout << "Выход из программы..." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);
}

#endif