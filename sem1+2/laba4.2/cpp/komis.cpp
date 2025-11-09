#include "../headers/komis.h"

const char* Komisia::get_komis_name()const
{
    return this->komis_name;
}


const char* Komisia::get_autobio()const
{
    return this->autobio;
}

void Komisia::set_komis_name(const char* kname)
{
    strncpy(this->komis_name, kname, M);
    this->komis_name[M - 1] = '\0';
}

void Komisia::set_autobio(const char* bio)
{
    strncpy(this->autobio, bio, M);
    this->autobio[M - 1] = '\0';
}

istream &operator>>(istream &in, Komisia &obj)
{
    in >> static_cast<Human&>(obj);
    cout << "введите имя комисии: ";
    in >> obj.komis_name;
    cout << "введите автобиографию: ";
    in >> obj.autobio;
    return in;
}

ostream &operator<<(ostream& out, Komisia &obj)
{
    out << static_cast<const Human&>(obj);
    out << setw(15) << left << obj.komis_name << setw(20) << left << obj.autobio;
    return out;
}

Komisia& Komisia::operator=(const Komisia& other)
{
    if (this != &other)
    {
        Human::operator=(other);
        strncpy(this->komis_name, other.komis_name, M);
        strncpy(this->autobio, other.autobio, M);
        this->komis_name[M - 1] = '\0';
        this->autobio[M - 1] = '\0';
    }
    return *this;
}


void Komisia::printHeader() 
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_Name" 
        << setw(8) << left << "Age"
        << setw(15) << left << "Komisiya"
        << setw(20) << left << "Autobio" << endl;
}


void Komisia::edit() {
    int fieldChoice;
    do {
        cout << "\n=== РЕДАКТИРОВАНИЕ KOMISIA ===" << endl;
        cout << "Текущий объект:" << endl;
        printHeader();
        cout << *this << endl;
        
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
                char newKomis[M];
                cout << "Введите новое название комиссии: ";
                cin >> newKomis;
                set_komis_name(newKomis);
                cout << "Название комиссии изменено!" << endl;
                break;
            }
            case 5: {
                char newBio[M];
                cout << "Введите новую автобиографию: ";
                cin >> newBio;
                set_autobio(newBio);
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