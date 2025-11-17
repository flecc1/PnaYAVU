#include "../headers/human.h"
#include "error.cpp"

int Human::get_age() const
{
    return this->age;
}

const char *Human::get_name() const
{
    return this->name;
}

const char *Human::get_second_name() const
{
    return this->second_name;
}

void Human::set_age(int n)
{
    if(n < 0 || n > 100)
    {
        throw Exp_vvoda(11, "RANGE_ERROR", "Возраст должен быть от 0 до 100");
    }
    this->age = n;
}

void Human::set_name(const char *new_name)
{
    if (strlen(new_name) == 0)
    {
        throw Exp_vvoda(12, "EMPTY_INPUT", "Имя не может быть пустым");
    }

    // Проверка на английские символы теперь в методах исключений
    // Убираем isEnglishText проверку здесь, так как она уже сделана в inputName
    strncpy(this->name, new_name, N - 1);
    this->name[N - 1] = '\0';
}

void Human::set_second_name(const char *new_second_name)
{
    if (strlen(new_second_name) == 0) 
    {
        throw Exp_vvoda(14, "EMPTY_INPUT", "Фамилия не может быть пустой");
    }
    // Проверка на английские символы теперь в методах исключений
    strncpy(this->second_name, new_second_name, N - 1);
    this->second_name[N - 1] = '\0';
}

Human& Human::operator=(const Human &other)
{
    if (this == &other)
    {
        return *this;
    }
    strncpy(this->name, other.name, N - 1);
    strncpy(this->second_name, other.second_name, N - 1);
    this->age = other.age;
    this->name[N - 1] = '\0';
    this->second_name[N - 1] = '\0';
    return *this;
}

istream &operator>>(istream &in, Human &obj)
{
    // Создаем объекты исключений для использования методов
    Exp_vvoda stringValidator;
    My_exception numValidator;
    
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

ostream &operator<<(ostream &out, const Human &obj)
{
    out << setw(12) << left << obj.name 
        << setw(14) << left << obj.second_name 
        << setw(8) << left << obj.age;
    return out;
}

void Human::printHeader()
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_Name" 
        << setw(8) << left << "Age" << endl;
}

void Human::edit() {
    int fieldChoice;
    // Создаем объекты исключений для использования методов
    Exp_vvoda stringValidator;
    My_exception numValidator;
    
    do {
        cout << "\n=== РЕДАКТИРОВАНИЕ HUMAN ===" << endl;
        cout << "Текущий объект:" << endl;
        printHeader();
        cout << *this << endl;
        
        cout << "\nВыберите поле для изменения:" << endl;
        cout << "1. Имя" << endl;
        cout << "2. Фамилия" << endl;
        cout << "3. Возраст" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите поле: ";
        
        fieldChoice = numValidator.inputNumber(0, 3);
        
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
            case 0:
                cout << "Выход из редактора..." << endl;
                break;
        }
    } while (fieldChoice != 0);
}