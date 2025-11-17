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
    
    // Создаем объект исключения для использования методов
    Exp_vvoda validator;
    
    // Ввод должности - цикл внутри метода исключения
    string dolg = validator.inputString("Введите название должности: ", in);
    obj.set_dolgnost(dolg.c_str());
    
    // Ввод специальности - цикл внутри метода исключения
    string spec = validator.inputString("Введите название специальности: ", in);
    obj.set_specialnost(spec.c_str());
    
    // Ввод списка трудов - цикл внутри метода исключения
    string truds = validator.inputString("Введите список трудов: ", in);
    obj.set_truds(truds.c_str());
    
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
    // Создаем объекты исключений для использования методов
    Exp_vvoda stringValidator;
    My_exception numValidator;
    
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
        
        fieldChoice = numValidator.inputNumber(0, 6);
        
        switch(fieldChoice) {
            case 1: {
                cout << "Введите новое имя: ";
                string newName = stringValidator.inputName();
                set_name(newName.c_str());
                cout << "Имя изменено!" << endl;
                break;
            }
            case 2: {
                cout << "Введите новую фамилию: ";
                string newSurname = stringValidator.inputSurname();
                set_second_name(newSurname.c_str());
                cout << "Фамилия изменена!" << endl;
                break;
            }
            case 3: {
                cout << "Введите новый возраст: ";
                int newAge = numValidator.inputNumber(0, 100);
                set_age(newAge);
                cout << "Возраст изменен!" << endl;
                break;
            }
            case 4: {
                string newDolg = stringValidator.inputString("Новая должность: ");
                set_dolgnost(newDolg.c_str());
                cout << "Должность изменена!" << endl;
                break;
            }
            case 5: {
                string newSpec = stringValidator.inputString("Новая специальность: ");
                set_specialnost(newSpec.c_str());
                cout << "Специальность изменена!" << endl;
                break;
            }
            case 6: {
                string newTruds = stringValidator.inputString("Новый список трудов: ");
                set_truds(newTruds.c_str());
                cout << "Список трудов изменен!" << endl;
                break;
            }
            case 0:
                cout << "Выход из редактора..." << endl;
                break;
        }
    } while (fieldChoice != 0);
}