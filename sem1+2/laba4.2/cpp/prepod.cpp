#include "../headers/prepod.h"

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
    strncpy(this->dolgnost, dolgnost, M);
    this->dolgnost[M - 1] = '\0';
}

void Prepod::set_specialnost(const char* specialnost)
{
    strncpy(this->specialnost, specialnost, M);
    this->specialnost[M - 1] = '\0';
}

void Prepod::set_truds(const char* truds)
{
    strncpy(this->truds, truds, M);
    this->truds[M - 1] = '\0';
}

istream& operator>>(istream& in, Prepod&obj)
{
    in >> static_cast<Human&>(obj);
    cout << "введите название должности: ";
    in >> obj.dolgnost;
    cout << "введите название специальности: ";
    in >> obj.specialnost;
    cout << "введите список трудов: ";
    in >> obj.truds;
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
        Human::operator=(other);  // Вызов базового оператора
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
            case 4: {
                char newDolgnost[M];
                cout << "Введите новую должность: ";
                cin >> newDolgnost;
                set_dolgnost(newDolgnost);
                cout << "Должность изменена!" << endl;
                break;
            }
            case 5: {
                char newSpec[M];
                cout << "Введите новую специальность: ";
                cin >> newSpec;
                set_specialnost(newSpec);
                cout << "Специальность изменена!" << endl;
                break;
            }
            case 6: {
                char newTruds[M];
                cout << "Введите новый список трудов: ";
                cin >> newTruds;
                set_truds(newTruds);
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