#include "../headers/prepod_komis.h"
#include "error.cpp"

const char* Prepod_Komis::get_spisok_rabot()const
{
    return this->spisok_rabot;
}

void Prepod_Komis::set_spisok_rabot(const char* new_spisok_rabot)
{
    if (strlen(new_spisok_rabot) == 0) 
    {
        throw Exp_vvoda(23, "EMPTY_INPUT", "Список работ не может быть пустым");
    }
    strncpy(this->spisok_rabot, new_spisok_rabot, M - 1);
    this->spisok_rabot[M - 1] = '\0';
}

istream &operator>>(istream &in, Prepod_Komis& obj)
{
    // Сначала вводим базовые данные Prepod
    in >> static_cast<Prepod&>(obj);
    
    // Создаем объект исключения для использования методов
    Exp_vvoda validator;
    
    // Ввод названия комиссии - цикл внутри метода исключения
    string komis = validator.inputString("Введите имя комиссии: ", in);
    obj.set_komis_name(komis.c_str());
    
    // Ввод автобиографии - цикл внутри метода исключения
    string bio = validator.inputString("Введите автобиографию: ", in);
    obj.set_autobio(bio.c_str());
    
    // Ввод списка работ - цикл внутри метода исключения
    string raboty = validator.inputString("Введите что делает член комиссии: ", in);
    obj.set_spisok_rabot(raboty.c_str());
    
    return in;
}

ostream &operator<<(ostream &out, Prepod_Komis& obj)
{
    out << static_cast<Prepod&>(obj);
    out << setw(15) << left << obj.komis_name << setw(20) << left << obj.autobio;
    out << setw(20) << left << obj.spisok_rabot;
    return out;
}

Prepod_Komis& Prepod_Komis::operator=(const Prepod_Komis& other)
{
    if (this != &other)
    {
        Prepod::operator=(other);
        Komisia::operator=(other);
        strncpy(this->spisok_rabot, other.spisok_rabot, M - 1);
        this->spisok_rabot[M - 1] = '\0';
    }
    return *this;
}

bool Prepod_Komis::operator==(const Prepod_Komis& other)
{
    // Сначала проверяем базовый класс Human (из-за виртуального наследования)
    if (!(static_cast<Human&>(*this) == static_cast<Human&>(const_cast<Prepod_Komis&>(other))))
        return false;

    // Проверяем поля Prepod
    if (other.dolgnost[0] != '\0' && strcmp(this->dolgnost, other.dolgnost) != 0)
        return false;
    if (other.specialnost[0] != '\0' && strcmp(this->specialnost, other.specialnost) != 0)
        return false;
    if (other.truds[0] != '\0' && strcmp(this->truds, other.truds) != 0)
        return false;

    // Проверяем поля Komisia
    if (other.autobio[0] != '\0' && strcmp(this->autobio, other.autobio) != 0)
        return false;
    if (other.komis_name[0] != '\0' && strcmp(this->komis_name, other.komis_name) != 0)
        return false;

    // Проверяем собственные поля
    if (other.spisok_rabot[0] != '\0' && strcmp(this->spisok_rabot, other.spisok_rabot) != 0)
        return false;

    return true;
}
void Prepod_Komis::printHeader() 
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_name" 
        << setw(8) << left << "Age"
        << setw(12) << left << "Dolgnost"
        << setw(15) << left << "Specialnost"
        << setw(15) << left << "Truds"
        << setw(15) << left << "Komisiya"
        << setw(20) << left << "Autobio" 
        << setw(20) << left << "Spisok_rabot" << endl;
}

void Prepod_Komis::edit() {
    Prepod::edit();  // Вызываем edit родительского класса Prepod (который уже вызывает Human::edit())
    int choice;
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    do {
        cout << "1. set commission name" << endl;
        cout << "2. set autobiography" << endl;
        cout << "3. set list of works" << endl;
        cout << "0. skip" << endl;
        cout << "your choice: ";
        
        choice = numValidator.inputNumber(cin, 0, 3);
        
        switch(choice) {
            case 1: {
                cout << "Enter commission name: ";
                string komis_name = validator.inputString("новое имя комисии: ");
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
            case 3: {
                cout << "Enter list of works: ";
                string spisok_rabot = validator.inputString("новый список работ: ");
                set_spisok_rabot(spisok_rabot.c_str());
                cout << "list of works editing" << endl;
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