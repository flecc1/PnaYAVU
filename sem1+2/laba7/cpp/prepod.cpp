#include "../headers/prepod.h"
#include "error.cpp"

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
    if (strlen(dolgnost) == 0) 
    {
        throw Exp_vvoda(18, "EMPTY_INPUT", "Должность не может быть пустой");
    }
    strncpy(this->dolgnost, dolgnost, M);
    this->dolgnost[M - 1] = '\0';
}

void Prepod::set_specialnost(const char* specialnost)
{
    if (strlen(specialnost) == 0) 
    {
        throw Exp_vvoda(19, "EMPTY_INPUT", "Специальность не может быть пустой");
    }
    strncpy(this->specialnost, specialnost, M);
    this->specialnost[M - 1] = '\0';
}

void Prepod::set_truds(const char* truds)
{
    if (strlen(truds) == 0) 
    {
        throw Exp_vvoda(20, "EMPTY_INPUT", "Список трудов не может быть пустым");
    }
    strncpy(this->truds, truds, M);
    this->truds[M - 1] = '\0';
}

istream& operator>>(istream& in, Prepod&obj)
{
    // Сначала вводим базовые данные Human
    in >> static_cast<Human&>(obj);
    
    // Создаем объект исключения для использования методов
    Exp_vvoda validator;
    
    // Ввод должности - цикл внутри метода исключения
    string dolg = validator.inputString("Введите название должности: ", in);
    obj.set_dolgnost(dolg.c_str());
    
    // Ввод специальности - цикл внутри метода исключения
    string spec = validator.inputString("Введите название специальности: ", in);
    obj.set_specialnost(spec.c_str());
    
    // Ввод списка трудов - цикл внутри метода исключения
    string truds = validator.inputString("Введите список трудов: ", in);
    obj.set_truds(truds.c_str());
    
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


bool Prepod::operator==(const Prepod &other)   
{
    if (!(static_cast<Human &>(*this) == static_cast<Human &>(const_cast<Prepod &>(other))))
        return false;
    if (other.dolgnost[0] != '\0' && strcmp(this->dolgnost, other.dolgnost) != 0)
        return false;
    if (other.specialnost[0] != '\0' && strcmp(this->specialnost, other.specialnost) != 0)
        return false;
    if (other.truds[0] != '\0' && strcmp(this->truds, other.truds) != 0)
        return false;
    return true;
}

Prepod& Prepod::operator=(const Prepod& other)
{
    if (this != &other)
    {
        Human::operator=(other);
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
    Human::edit();  // Вызываем edit родительского класса
    int choice;
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    do {
        cout << "1. set position" << endl;
        cout << "2. set specialty" << endl;
        cout << "3. set list of works" << endl;
        cout << "0. skip" << endl;
        cout << "your choice: ";
        
        choice = numValidator.inputNumber(cin, 0, 3);
        
        switch(choice) {
            case 1: {
                cout << "Enter position: ";
                string dolgnost = validator.inputString("новая должность: ");
                set_dolgnost(dolgnost.c_str());
                cout << "position editing" << endl;
                break;
            }
            case 2: {
                cout << "Enter specialty: ";
                string specialnost = validator.inputString("новая специальность: ");
                set_specialnost(specialnost.c_str());
                cout << "specialty editing" << endl;
                break;
            }
            case 3: {
                cout << "Enter list of works: ";
                string truds = validator.inputString("новый список трудов: ");
                set_truds(truds.c_str());
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

// Оператор для файлов
istream& readFromFile(istream &in, Prepod &obj)
{
    // Сначала читаем Human часть
    readFromFile(in, static_cast<Human&>(obj));
    
    // Потом Prepod часть
    string dolgnost, specialnost, truds;
    
    in >> dolgnost >> specialnost;
    // Для truds читаем остаток строки
    getline(in, truds);
    if (!truds.empty() && truds[0] == ' ') {
        truds.erase(0, 1); // Убираем первый пробел
    }
    
    obj.set_dolgnost(dolgnost.c_str());
    obj.set_specialnost(specialnost.c_str());
    obj.set_truds(truds.c_str());
    
    return in;
}

// Оператор для файлов
ostream& writeToFile(ostream& out, const Prepod &obj)
{
    // Сначала пишем Human часть
    writeToFile(out, static_cast<const Human&>(obj));
    
    // Потом Prepod часть
    out << " " << obj.dolgnost << " " << obj.specialnost << " " << obj.truds;
    return out;
}