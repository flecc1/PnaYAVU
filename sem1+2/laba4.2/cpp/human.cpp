#include "../headers/human.h"

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
    this->age = n;
}

void Human::set_name(const char *new_name)
{
    strncpy(this->name, new_name, N - 1);
    this->name[N - 1] = '\0';
}
void Human::set_second_name(const char *new_second_name)
{
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
    cout << "введите имя: ";
    in >> obj.name;
    cout << "введите фамилию: ";
    in >> obj.second_name;
    cout << "введите возраст: ";
    in >> obj.age;
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
        cin >> fieldChoice;
        
        switch(fieldChoice) {
            case 1: {
                char newName[N];
                cout << "Введите новое имя: ";
                cin >> newName;
                set_name(newName);
                cout << "Имя изменено!" << endl;
                break;
            }
            case 2: {
                char newSurname[N];
                cout << "Введите новую фамилию: ";
                cin >> newSurname;
                set_second_name(newSurname);
                cout << "Фамилия изменена!" << endl;
                break;
            }
            case 3: {
                int newAge;
                cout << "Введите новый возраст: ";
                cin >> newAge;
                set_age(newAge);
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