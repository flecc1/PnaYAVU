#include "../headers/student.h"

void Student::set_sr_bal(double sr_bal)
{
    this->sr_bal = sr_bal;
}

void Student::set_stependiya(int stepuha)
{
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
    cout << "введите средний бал: ";
    in >> obj.sr_bal;
    cout << "введите степендию: ";
    in >> obj.stependiya;
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
                double newBal;
                cout << "Введите новый средний балл: ";
                cin >> newBal;
                set_sr_bal(newBal);
                cout << "Средний балл изменен!" << endl;
                break;
            }
            case 5: {
                int newStep;
                cout << "Введите новую стипендию: ";
                cin >> newStep;
                set_stependiya(newStep);
                cout << "Стипендия изменена!" << endl;
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