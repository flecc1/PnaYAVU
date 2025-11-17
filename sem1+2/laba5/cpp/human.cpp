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

    string name_str(new_name);
    if (!isEnglishText(name_str)) 
    {
        throw Exp_vvoda(13, "LANGUAGE_ERROR", "Имя должно содержать только английские буквы");
    }

    strncpy(this->name, new_name, N - 1);
    this->name[N - 1] = '\0';
}

void Human::set_second_name(const char *new_second_name)
{
    if (strlen(new_second_name) == 0) 
    {
        throw Exp_vvoda(14, "EMPTY_INPUT", "Фамилия не может быть пустой");
    }
    string sname_str(new_second_name);
    if (!isEnglishText(sname_str)) 
    {
        throw Exp_vvoda(15, "LANGUAGE_ERROR", "Фамилия должна содержать только английские буквы");
    }
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
    // Ввод имени с повторением при ошибке

            clearInputBuffer();
            cout << "Введите имя: ";
            string name = readName();
            obj.set_name(name.c_str());

            cout << "Введите фамилию: ";
            string sname = readSurname();
            obj.set_second_name(sname.c_str());


    
    // Ввод возраста с повторением при ошибке

            cout << "Введите возраст: ";
            int age = inputNumber(0, 100);
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
        
        try {
            fieldChoice = inputNumber(0, 3);
            
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