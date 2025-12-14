#include "../headers/human.h"
#include "error.cpp"

int Human::get_age() const
{
    return this->age;
}

const char* Human::get_name() const
{
    return this->name;
}

const char* Human::get_second_name() const
{
    return this->second_name;
}

void Human::set_age(int n)
{
    this->age = n;
}

void Human::set_name(const char* new_name)
{
    strncpy(this->name, new_name, N - 1);
    this->name[N - 1] = '\0';
}

void Human::set_second_name(const char* new_second_name)
{
    strncpy(this->second_name, new_second_name, N - 1);
    this->second_name[N - 1] = '\0';
}

Human& Human::operator=(const Human& other)
{
    if(this != &other)
    {
        strncpy(this->name, other.name, N - 1);
        strncpy(this->second_name, other.second_name, N - 1);
        this->age = other.age;
        this->name[N - 1] = '\0';
        this->second_name[N - 1] = '\0';
    }
    return *this;
}

bool Human::operator==(const Human &other)
{
    if (other.name[0] != '\0' && strcmp(this->name, other.name) != 0)
        return false;
    if (other.second_name[0] != '\0' && strcmp(this->second_name, other.second_name) != 0)
        return false;
    if (other.age != -1 && this->age != other.age)
        return false;
    return true;
}

istream &operator>>(istream &in, Human &obj)
{
    // Создаем объекты исключений для использования методов
    Exp_vvoda stringValidator;
    Exp_vvoda numValidator;
    
    // Ввод имени - цикл внутри метода исключения
    cout << "Введите имя: ";
    string name = stringValidator.inputName(in);
    obj.set_name(name.c_str());
    
    // Ввод фамилии - цикл внутри метода исключения  
    cout << "Введите фамилию: ";
    string sname = stringValidator.inputSurname(in);
    obj.set_second_name(sname.c_str());
    
    // Ввод возраста - цикл внутри метода исключения
    cout << "Введите возраст: ";
    int age = numValidator.inputNumber(in, 0, 100);
    obj.set_age(age);
    
    return in;
}

// Оператор для файлов (без валидации)
istream &readFromFile(istream &in, Human &obj)
{
    string name, sname;
    int age;
    
    in >> name >> sname >> age;
    obj.set_name(name.c_str());
    obj.set_second_name(sname.c_str());
    obj.set_age(age);
    
    return in;
}

// Оператор для консоли
ostream &operator<<(ostream &out, const Human &obj)
{
    out << setw(12) << left << obj.name 
        << setw(14) << left << obj.second_name 
        << setw(8) << left << obj.age;
    return out;
}

// Оператор для файлов
ostream &writeToFile(ostream &out, const Human &obj)
{
    out << obj.name << " " << obj.second_name << " " << obj.age;
    return out;
}

void Human::printHeader() 
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_name" 
        << setw(8) << left << "Age" << endl;
}

void Human::edit() {
    int choice;
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    do {
        cout << "1. set name" << endl;
        cout << "2. set surname" << endl;
        cout << "3. set age" << endl;
        cout << "0. skip" << endl;
        cout << "your choice: ";
        
        choice = numValidator.inputNumber(cin, 0, 3);
        
        switch(choice) {
            case 1: {
                cout << "Enter name: ";
                string name = validator.inputName();
                set_name(name.c_str());
                cout << "name editing" << endl;
                break;
            }
            case 2: {
                cout << "Enter surname: ";
                string second_name = validator.inputSurname();
                set_second_name(second_name.c_str());
                cout << "surname editing" << endl;
                break;
            }
            case 3: {
                cout << "Enter age: ";
                int age;
                age = numValidator.inputNumber(cin, 0, 150);
                set_age(age);
                cout << "age editing" << endl;
                break;
            }
            case 0: {
                break;
            }
            default: {
                cout << "error choice" << endl;
                break;
            }
        }
    } while (choice != 0);
}