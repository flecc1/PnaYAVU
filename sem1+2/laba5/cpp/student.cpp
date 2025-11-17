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
    in >> static_cast<Human&>(obj);
    
    while (true) {
        try {
            cout << "Введите средний балл: ";
            double bal = inputDouble(0.0, 10.0);
            obj.set_sr_bal(bal);
            break;
        } catch (Exp_vvoda& e) {
            cout << "Ошибка при вводе среднего балла: ";
            e.printError();
            cout << "Повторите ввод." << endl;
        }
    }
    
    // Ввод стипендии с повторением при ошибке
    while (true) {
        try {
            cout << "Введите стипендию: ";
            int step = inputNumber(0, 100000);
            obj.set_stependiya(step);
            break;
        } catch (Exp_vvoda& e) {
            cout << "Ошибка при вводе стипендии: ";
            e.printError();
            cout << "Повторите ввод." << endl;
        }
    }
    
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

void Student::printHeader() 
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_name" 
        << setw(8) << left << "Age"
        << setw(12) << left << "Sr_bal"       
        << setw(12) << left << "Stipendiya" << endl; 
}

void Student::edit() {
    int fieldChoice;
    do {
        cout << "\n=== РЕДАКТИРОВАНИЕ STUDENT ===" << endl;
        cout << "Текущий объект:" << endl;
        printHeader();
        cout << *this << endl;
        
        cout << "\nВыберите поле для изменения:" << endl;
        cout << "1. Имя" << endl;
        cout << "2. Фамилия" << endl;
        cout << "3. Возраст" << endl;
        cout << "4. Средний балл" << endl;
        cout << "5. Стипендия" << endl;
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
                    double newBal = inputDouble(0.0, 10.0);
                    set_sr_bal(newBal);
                    cout << "Средний балл изменен!" << endl;
                    break;
                }
                case 5: {
                    int newStep = inputNumber(0, 100000);
                    set_stependiya(newStep);
                    cout << "Стипендия изменена!" << endl;
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