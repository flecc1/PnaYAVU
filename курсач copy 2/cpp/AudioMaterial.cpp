// AudioMaterial.cpp
#include "../headers/AudioMaterial.h"
#include "../headers/excep_vvoda.h"

void AudioMaterial::printHeader() const
{
    cout << setw(20) << left << "Nazvanie" 
        << setw(20) << left << "Avtor" 
        << setw(8) << left << "God"
        << setw(15) << left << "Zhanr"
        << setw(12) << left << "Kopii"
        << setw(10) << left << "Cena"
        << setw(12) << left << "Dlitelnost"
        << setw(15) << left << "Format" << endl;
}

int AudioMaterial::getDuration() const 
{ 
    return duration; 
}
string AudioMaterial::getFormat() const 
{ 
    return format; 
}

void AudioMaterial::setDuration(int duration) 
{ 
    this->duration = duration; 
}
void AudioMaterial::setFormat(const string &format) 
{ 
    this->format = format; 
}

void AudioMaterial::edit()
{
    LibraryItem::edit();
    int choice;
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    do {
        cout << "1. Изменить длительность" << endl;
        cout << "2. Изменить формат" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        
        choice = numValidator.inputNumber(cin, 0, 2);
        
        switch(choice) {
            case 1: {
                cout << "Введите длительность (мин): ";
                int duration = numValidator.inputNumber(cin, 1, 10000);
                setDuration(duration);
                cout << "Длительность изменена" << endl;
                break;
            }
            case 2: {
                cout << "Введите формат: ";
                string format = validator.inputString("", cin);
                setFormat(format);
                cout << "Формат изменен" << endl;
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

bool AudioMaterial::operator==(const AudioMaterial& other) const
{
    if (!(static_cast<const LibraryItem&>(*this) == static_cast<const LibraryItem&>(other)))
        return false;
    
    if (other.duration != 0 && this->duration != other.duration)
        return false;
    if (other.format != "" && this->format != other.format)
        return false;
    
    return true;
}

istream &operator>>(istream &in, AudioMaterial &obj)
{
    in >> static_cast<LibraryItem &>(obj);
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    cout << "введите длительность (мин): ";
    int duration = numValidator.inputNumber(in, 1, 10000);
    obj.setDuration(duration);
    
    cout << "введите формат: ";
    string format = validator.inputString("", in);
    obj.setFormat(format);
    
    return in;
}

istream &readFromFile(istream &in, AudioMaterial &obj)
{
    LibraryItem& base = static_cast<LibraryItem&>(obj);
    readFromFile(in, base);
    int duration;
    string format;
    in >> duration >> format;
    obj.setDuration(duration);
    obj.setFormat(format);
    return in;
}

ostream &writeToFile(ostream &out, const AudioMaterial &obj)
{
    writeToFile(out, static_cast<const LibraryItem&>(obj));
    out << " " << obj.duration << " " << obj.format;
    return out;
}

ostream &operator<<(ostream &out, AudioMaterial &obj)
{
    out << static_cast<LibraryItem &>(obj)
        << setw(12) << left << obj.duration
        << setw(15) << left << obj.format;
    return out;
}

AudioMaterial &AudioMaterial::operator=(const AudioMaterial &other)
{
    if (this != &other)
    {
        LibraryItem::operator=(other);
        duration = other.duration;
        format = other.format;
    }
    return *this;
}