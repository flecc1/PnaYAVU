#include "../headers/student.h"
#include "error.cpp"

void Student::set_sr_bal(double sr_bal)
{
    if(sr_bal < 0.0 || sr_bal > 10.0)
    {
        throw Exp_vvoda(16, "RANGE_ERROR", "Средний балл должен быть от 0.0 до 10.0");
    }
    this->sr_bal = sr_bal;
}

void Student::set_stependiya(int stepuha)
{
    if (stepuha < 0) 
    {
        throw Exp_vvoda(17, "RANGE_ERROR", "Стипендия не может быть отрицательной");
    }
    this->stependiya = stepuha;
}

double Student::get_sr_bal()const
{
    return this->sr_bal;
}

int Student::get_stependiya()const
{
    return this->stependiya;
}

istream& operator>>(istream &in, Student &obj)
{
    // Сначала вводим базовые данные Human
    in >> static_cast<Human&>(obj);
    
    // Создаем объект исключения для использования методов
    Exp_vvoda validator;
    
    // Ввод среднего балла - цикл внутри метода исключения
    cout << "Введите средний балл: ";
    double bal = validator.inputDouble(in, 0.0, 10.0);
    obj.set_sr_bal(bal);
    
    // Ввод стипендии - цикл внутри метода исключения
    cout << "Введите стипендию: ";
    int step = validator.inputNumber(in, 0, 100000);
    obj.set_stependiya(step);
    
    return in;
}

ostream& operator<<(ostream& out, Student &obj)
{
    out << static_cast<const Human&>(obj);
    out << setw(12) << left << obj.sr_bal << setw(12) << left << obj.stependiya;
    return out;
}

Student& Student::operator=(const Student &other)
{
    if(this != &other)
    {
        Human::operator=(other);
        this->sr_bal = other.sr_bal;
        this->stependiya = other.stependiya;
    }
    return *this;
}

bool Student::operator==(const Student &other)
{
    if (!(static_cast<Human &>(*this) == static_cast<Human &>(const_cast<Student &>(other))))
        return false;

    // Если в шаблоне поиска средний балл установлен (не 0.0), то сравниваем
    if (other.sr_bal != -1 && this->sr_bal != other.sr_bal)
        return false;
        
    // Если в шаблоне поиска стипендия установлена (не -1), то сравниваем
    if (other.stependiya != -1 && this->stependiya != other.stependiya)
        return false;

    return true;
}

void Student::printHeader() 
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_name" 
        << setw(8) << left << "Age"
        << setw(12) << left << "Sr_bal"       
        << setw(12) << left << "Stipendiya" << endl; 
}

void Student::edit() {
    Human::edit();  // Вызываем edit родительского класса
    int choice;
    Exp_vvoda numValidator;
    
    do {
        cout << "1. set average score" << endl;
        cout << "2. set scholarship" << endl;
        cout << "0. skip" << endl;
        cout << "your choice: ";
        
        choice = numValidator.inputNumber(cin, 0, 2);
        
        switch(choice) {
            case 1: {
                cout << "Enter average score: ";
                double sr_bal;
                sr_bal = numValidator.inputDouble(cin, 0.0, 10.0);
                set_sr_bal(sr_bal);
                cout << "average score editing" << endl;
                break;
            }
            case 2: {
                cout << "Enter scholarship: ";
                int stependiya;
                stependiya = numValidator.inputNumber(cin, 0, 100000);
                set_stependiya(stependiya);
                cout << "scholarship editing" << endl;
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