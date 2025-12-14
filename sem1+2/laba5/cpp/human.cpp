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

ostream &operator<<(ostream &out, const Human &obj)
{
    out << setw(12) << left << obj.name 
        << setw(14) << left << obj.second_name 
        << setw(8) << left << obj.age;
    return out;
}

bool Human::operator==(const Human &other)
{
    // Если в шаблоне поиска возраст установлен (не 0), то сравниваем
    if (other.age != -1 && this->age != other.age)
        return false;

    // Если в шаблоне поиска имя установлено (не пустая строка), то сравниваем
    if (other.name[0] != '\0' && strcmp(this->name, other.name) != 0)
        return false;
        
    // Если в шаблоне поиска фамилия установлена (не пустая строка), то сравниваем  
    if (other.second_name[0] != '\0' && strcmp(this->second_name, other.second_name) != 0)
        return false;

    return true;
}
void Human::printHeader()
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_Name" 
        << setw(8) << left << "Age" << endl;
}

void Human::edit() {
    int choice;
    Exp_vvoda numValidator;
    Exp_vvoda stringValidator;
    
    do {
        cout << "1. set name" << endl;
        cout << "2. set second name" << endl;
        cout << "3. set age" << endl;
        cout << "0. skip" << endl;
        cout << "your choice: ";
        
        choice = numValidator.inputNumber(cin, 0, 3);
        
        switch(choice) {
            case 1: {
                cout << "Enter name: ";
                string name = stringValidator.inputName();
                set_name(name.c_str());
                cout << "name editing" << endl;
                break;
            }
            case 2: {
                cout << "Enter second name: ";
                string second_name = stringValidator.inputSurname();
                set_second_name(second_name.c_str());
                cout << "second name editing" << endl;
                break;
            }
            case 3: {
                cout << "Enter age: ";
                int age = numValidator.inputNumber(cin, 0, 100);
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