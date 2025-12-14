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
    
    // Создаем объект исключения для использования методов
    Exp_vvoda validator;
    
    // Ввод названия комиссии - цикл внутри метода исключения
    string komis = validator.inputString("Введите имя комиссии: ", in);
    obj.set_komis_name(komis.c_str());
    
    // Ввод автобиографии - цикл внутри метода исключения
    string bio = validator.inputString("Введите автобиографию: ", in);
    obj.set_autobio(bio.c_str());
    
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

bool Komisia::operator==(const Komisia &other)
{
    if (!(static_cast<Human &>(*this) == static_cast<Human &>(const_cast<Komisia &>(other))))
        return false;

    if (other.autobio[0] != '\0' && strcmp(this->autobio, other.autobio) != 0)
        return false;
    if (other.komis_name[0] != '\0' && strcmp(this->komis_name, other.komis_name) != 0)
        return false;

    return true;
}

void Komisia::edit() {
    Human::edit();  // Вызываем edit родительского класса
    int choice;
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    do {
        cout << "1. set commission name" << endl;
        cout << "2. set autobiography" << endl;
        cout << "0. skip" << endl;
        cout << "your choice: ";
        
        choice = numValidator.inputNumber(cin, 0, 2);
        
        switch(choice) {
            case 1: {
                cout << "Enter commission name: ";
                string komis_name = validator.inputString("новая комисия: ");
                set_komis_name(komis_name.c_str());
                cout << "commission name editing" << endl;
                break;
            }
            case 2: {
                cout << "Enter autobiography: ";
                string autobio = validator.inputString("новая автобиография: ");
                set_autobio(autobio.c_str());
                cout << "autobiography editing" << endl;
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