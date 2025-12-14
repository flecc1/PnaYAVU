// EducationalAudio.cpp
#include "../headers/EducationalAudio.h"
#include "../headers/excep_vvoda.h"

void EducationalAudio::printHeader() const
{
    cout << setw(20) << left << "Nazvanie" 
        << setw(20) << left << "Avtor" 
        << setw(8) << left << "God"
        << setw(15) << left << "Zhanr"
        << setw(12) << left << "Kopii"
        << setw(10) << left << "Cena"
        << setw(12) << left << "Dlitelnost"
        << setw(15) << left << "Format"
        << setw(20) << left << "Instruktor"
        << setw(20) << left << "Predmet" << endl;
}

string EducationalAudio::getInstructor() const 
{ 
    return instructor;
}
string EducationalAudio::getSubject() const 
{ 
    return subject; 
}

void EducationalAudio::setInstructor(const string &instructor) 
{ 
    this->instructor = instructor; 
}
void EducationalAudio::setSubject(const string &subject) 
{ 
    this->subject = subject; 
}

void EducationalAudio::edit()
{
    AudioMaterial::edit();
    int choice;
    Exp_vvoda validator;
    
    do {
        cout << "1. Изменить инструктора" << endl;
        cout << "2. Изменить предмет" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        
        Exp_vvoda numValidator;
        choice = numValidator.inputNumber(cin, 0, 2);
        
        switch(choice) {
            case 1: {
                cout << "Введите инструктора: ";
                string instructor = validator.inputString("", cin);
                setInstructor(instructor);
                cout << "Инструктор изменен" << endl;
                break;
            }
            case 2: {
                cout << "Введите предмет: ";
                string subject = validator.inputString("", cin);
                setSubject(subject);
                cout << "Предмет изменен" << endl;
                break;
            }
            case 0: {
                break;
            }
            default: {
                cout << "Неверный выбор" << endl;
                break;
            }
        }
    } while (choice != 0);
}

bool EducationalAudio::operator==(const EducationalAudio& other) const
{
    if (!(static_cast<const AudioMaterial&>(*this) == static_cast<const AudioMaterial&>(other)))
        return false;
    
    if (other.instructor != "" && this->instructor != other.instructor)
        return false;
    if (other.subject != "" && this->subject != other.subject)
        return false;
    
    return true;
}

istream &operator>>(istream &in, EducationalAudio &obj)
{
    in >> static_cast<AudioMaterial &>(obj);
    Exp_vvoda validator;
    
    cout << "введите инструктора: ";
    string instructor = validator.inputString("", in);
    obj.setInstructor(instructor);
    
    cout << "введите предмет: ";
    string subject = validator.inputString("", in);
    obj.setSubject(subject);
    
    return in;
}

istream &readFromFile(istream &in, EducationalAudio &obj)
{
    AudioMaterial& base = static_cast<AudioMaterial&>(obj);
    readFromFile(in, base);
    string instructor, subject;
    in >> instructor >> subject;
    obj.setInstructor(instructor);
    obj.setSubject(subject);
    return in;
}

ostream &writeToFile(ostream &out, const EducationalAudio &obj)
{
    writeToFile(out, static_cast<const AudioMaterial&>(obj));
    out << " " << obj.instructor << " " << obj.subject;
    return out;
}

ostream &operator<<(ostream &out, EducationalAudio &obj)
{
    out << static_cast<AudioMaterial &>(obj)
        << setw(20) << left << obj.instructor
        << setw(20) << left << obj.subject;
    return out;
}

EducationalAudio &EducationalAudio::operator=(const EducationalAudio &other)
{
    if (this != &other)
    {
        AudioMaterial::operator=(other);
        instructor = other.instructor;
        subject = other.subject;
    }
    return *this;
}