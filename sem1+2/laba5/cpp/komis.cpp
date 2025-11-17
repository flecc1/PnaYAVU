#include "../headers/komis.h"
#include "error.cpp"

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
    if (strlen(kname) == 0) 
    {
        throw Exp_vvoda(21, "EMPTY_INPUT", "Название комиссии не может быть пустым");
    }
    strncpy(this->komis_name, kname, M);
    this->komis_name[M - 1] = '\0';
}

void Komisia::set_autobio(const char* bio)
{
    if (strlen(bio) == 0) 
    {
        throw Exp_vvoda(22, "EMPTY_INPUT", "Автобиография не может быть пустой");
    }
    strncpy(this->autobio, bio, M);
    this->autobio[M - 1] = '\0';
}

istream &operator>>(istream &in, Komisia &obj)
{
    // Сначала вводим базовые данные Human
    in >> static_cast<Human&>(obj);
    
    // Ввод названия комиссии с повторением при ошибке
    while (true) {
        try {
            clearInputBuffer();
            cout << "Введите имя комиссии: ";
            string komis = readString("");
            obj.set_komis_name(komis.c_str());
            break;
        } catch (Exp_vvoda& e) {
            cout << "Ошибка при вводе названия комиссии: ";
            e.printError();
            cout << "Повторите ввод." << endl;
        }
    }
    
    // Ввод автобиографии с повторением при ошибке
    while (true) {
        try {
            cout << "Введите автобиографию: ";
            string bio = readString("");
            obj.set_autobio(bio.c_str());
            break;
        } catch (Exp_vvoda& e) {
            cout << "Ошибка при вводе автобиографии: ";
            e.printError();
            cout << "Повторите ввод." << endl;
        }
    }
    
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
        
        try {
            fieldChoice = inputNumber(0, 5);
            
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
                    string newKomis = readString("Новое название комиссии: ");
                    set_komis_name(newKomis.c_str());
                    cout << "Название комиссии изменено!" << endl;
                    break;
                }
                case 5: {
                    clearInputBuffer();
                    string newBio = readString("Новая автобиография: ");
                    set_autobio(newBio.c_str());
                    cout << "Автобиография изменена!" << endl;
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