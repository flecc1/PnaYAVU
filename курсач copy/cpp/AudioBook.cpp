// AudioBook.cpp
#include "../headers/AudioBook.h"
#include "../headers/excep_vvoda.h"

void AudioBook::printHeader() const
{
    cout << setw(20) << left << "Nazvanie" 
        << setw(20) << left << "Avtor" 
        << setw(8) << left << "God"
        << setw(15) << left << "Zhanr"
        << setw(12) << left << "Kopii"
        << setw(10) << left << "Cena"
        << setw(12) << left << "Dlitelnost"
        << setw(15) << left << "Format"
        << setw(10) << left << "Glavy"
        << setw(20) << left << "Chtec" << endl;
}

int AudioBook::getChapters() const { return chapters; }
string AudioBook::getNarrator() const { return narrator; }

void AudioBook::setChapters(int chapters) { this->chapters = chapters; }
void AudioBook::setNarrator(const string &narrator) { this->narrator = narrator; }

void AudioBook::edit()
{
    AudioMaterial::edit();
    int choice;
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    do {
        cout << "1. Изменить количество глав" << endl;
        cout << "2. Изменить чтеца" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        
        choice = numValidator.inputNumber(cin, 0, 2);
        
        switch(choice) {
            case 1: {
                cout << "Введите количество глав: ";
                int chapters = numValidator.inputNumber(cin, 1, 1000);
                setChapters(chapters);
                cout << "Количество глав изменено" << endl;
                break;
            }
            case 2: {
                cout << "Введите чтеца: ";
                string narrator = validator.inputString("", cin);
                setNarrator(narrator);
                cout << "Чтец изменен" << endl;
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

bool AudioBook::operator==(const AudioBook& other) const
{
    if (!(static_cast<const AudioMaterial&>(*this) == static_cast<const AudioMaterial&>(other)))
        return false;
    
    if (other.chapters != 0 && this->chapters != other.chapters)
        return false;
    if (other.narrator != "" && this->narrator != other.narrator)
        return false;
    
    return true;
}

istream &operator>>(istream &in, AudioBook &obj)
{
    in >> static_cast<AudioMaterial &>(obj);
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    cout << "Введите количество глав: ";
    int chapters = numValidator.inputNumber(in, 1, 1000);
    obj.setChapters(chapters);
    
    cout << "Введите чтеца: ";
    string narrator = validator.inputString("", in);
    obj.setNarrator(narrator);
    
    return in;
}

istream &readFromFile(istream &in, AudioBook &obj)
{
    AudioMaterial& base = static_cast<AudioMaterial&>(obj);
    readFromFile(in, base);
    int chapters;
    string narrator;
    in >> chapters >> narrator;
    obj.setChapters(chapters);
    obj.setNarrator(narrator);
    return in;
}

ostream &writeToFile(ostream &out, const AudioBook &obj)
{
    writeToFile(out, static_cast<const AudioMaterial&>(obj));
    out << " " << obj.chapters << " " << obj.narrator;
    return out;
}

ostream &operator<<(ostream &out, AudioBook &obj)
{
    out << static_cast<AudioMaterial &>(obj)
        << setw(10) << left << obj.chapters
        << setw(20) << left << obj.narrator;
    return out;
}

AudioBook &AudioBook::operator=(const AudioBook &other)
{
    if (this != &other)
    {
        AudioMaterial::operator=(other);
        chapters = other.chapters;
        narrator = other.narrator;
    }
    return *this;
}