#include "../headers/prepod.h"
#include "error.cpp"

const char* Prepod::get_dolgnost()const
{
    return this->dolgnost;
}

const char* Prepod::get_specialnost()const
{
    return this->specialnost;
}

const char* Prepod::get_truds()const
{
    return this->truds;
}

void Prepod::set_dolgnost(const char* dolgnost)
{
    if (strlen(dolgnost) == 0) 
    {
        throw Exp_vvoda(18, "EMPTY_INPUT", "Должность не может быть пустой");
    }
    strncpy(this->dolgnost, dolgnost, M);
    this->dolgnost[M - 1] = '\0';
}

void Prepod::set_specialnost(const char* specialnost)
{
    if (strlen(specialnost) == 0) 
    {
        throw Exp_vvoda(19, "EMPTY_INPUT", "Специальность не может быть пустой");
    }
    strncpy(this->specialnost, specialnost, M);
    this->specialnost[M - 1] = '\0';
}

void Prepod::set_truds(const char* truds)
{
    if (strlen(truds) == 0) 
    {
        throw Exp_vvoda(20, "EMPTY_INPUT", "Список трудов не может быть пустым");
    }
    strncpy(this->truds, truds, M);
    this->truds[M - 1] = '\0';
}

istream& operator>>(istream& in, Prepod&obj)
{
    // Сначала вводим базовые данные Human
    in >> static_cast<Human&>(obj);
    
    // Ввод должности с повторением при ошибке
    while (true) {
        try {
            clearInputBuffer();
            cout << "Введите название должности: ";
            string dolg = readString("");
            obj.set_dolgnost(dolg.c_str());
            break;
        } catch (Exp_vvoda& e) {
            cout << "Ошибка при вводе должности: ";
            e.printError();
            cout << "Повторите ввод." << endl;
        }
    }
    
    // Ввод специальности с повторением при ошибке
    while (true) {
        try {
            cout << "Введите название специальности: ";
            string spec = readString("");
            obj.set_specialnost(spec.c_str());
            break;
        } catch (Exp_vvoda& e) {
            cout << "Ошибка при вводе специальности: ";
            e.printError();
            cout << "Повторите ввод." << endl;
        }
    }
    
    // Ввод списка трудов с повторением при ошибке
    while (true) {
        try {
            cout << "Введите список трудов: ";
            string truds = readString("");
            obj.set_truds(truds.c_str());
            break;
        } catch (Exp_vvoda& e) {
            cout << "Ошибка при вводе списка трудов: ";
            e.printError();
            cout << "Повторите ввод." << endl;
        }
    }
    
    return in;
}

ostream& operator<<(ostream& out, Prepod& obj)
{
    out << static_cast<const Human&>(obj);
    out << setw(12) << left << obj.dolgnost 
        << setw(15) << left << obj.specialnost 
        << setw(15) << left << obj.truds;
    return out;
}

Prepod& Prepod::operator=(const Prepod& other)
{
    if (this != &other)
    {
        Human::operator=(other);
        strncpy(this->dolgnost, other.dolgnost, M - 1);
        strncpy(this->specialnost, other.specialnost, M - 1);
        strncpy(this->truds, other.truds, M - 1);
        this->dolgnost[M - 1] = '\0';
        this->specialnost[M - 1] = '\0';
        this->truds[M - 1] = '\0';
    }
    return *this;
}

void Prepod::printHeader() 
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_name" 
        << setw(8) << left << "Age"
        << setw(12) << left << "Dolgnost"
        << setw(15) << left << "Specialnost"
        << setw(15) << left << "Truds" << endl;
}

void Prepod::edit() {
    int fieldChoice;
    do {
        cout << "\n=== РЕДАКТИРОВАНИЕ PREPOD ===" << endl;
        cout << "Текущий объект:" << endl;
        printHeader();
        cout << *this << endl;
        
        cout << "\nВыберите поле для изменения:" << endl;
        cout << "1. Имя" << endl;
        cout << "2. Фамилия" << endl;
        cout << "3. Возраст" << endl;
        cout << "4. Должность" << endl;
        cout << "5. Специальность" << endl;
        cout << "6. Список трудов" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите поле: ";
        
        try {
            fieldChoice = inputNumber(0, 6);
            
            switch(fieldChoice) {
                case 1: {
                    clearInputBuffer();
                    string newName = readName();
                    set_name(newName.c_str());
                    cout << "Имя изменено!" << endl;
                    break;
                }
                case 2: {
                    clearInputBuffer();
                    string newSurname = readSurname();
                    set_second_name(newSurname.c_str());
                    cout << "Фамилия изменена!" << endl;
                    break;
                }
                case 3: {
                    int newAge = inputNumber(0, 100);
                    set_age(newAge);
                    cout << "Возраст изменен!" << endl;
                    break;
                }
                case 4: {
                    clearInputBuffer();
                    string newDolg = readString("Новая должность: ");
                    set_dolgnost(newDolg.c_str());
                    cout << "Должность изменена!" << endl;
                    break;
                }
                case 5: {
                    clearInputBuffer();
                    string newSpec = readString("Новая специальность: ");
                    set_specialnost(newSpec.c_str());
                    cout << "Специальность изменена!" << endl;
                    break;
                }
                case 6: {
                    clearInputBuffer();
                    string newTruds = readString("Новый список трудов: ");
                    set_truds(newTruds.c_str());
                    cout << "Список трудов изменен!" << endl;
                    break;
                }
                case 0:
                    cout << "Выход из редактора..." << endl;
                    break;
            }
        } catch (Exp_vvoda& e) {
            cout << "Ошибка при вводе: ";
            e.printError();
            fieldChoice = -1;
        }
    } while (fieldChoice != 0);
}