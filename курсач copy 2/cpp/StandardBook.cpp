// StandardBook.cpp
#include "../headers/StandardBook.h"
#include "../headers/excep_vvoda.h"

void StandardBook::printHeader() const
{
    cout << setw(20) << left << "Nazvanie" 
        << setw(20) << left << "Avtor" 
        << setw(8) << left << "God"
        << setw(15) << left << "Zhanr"
        << setw(12) << left << "Kopii"
        << setw(10) << left << "Cena"
        << setw(8) << left << "Stranic"
        << setw(15) << left << "ISBN"
        << setw(20) << left << "Izdatelstvo"
        << setw(15) << left << "Oblozhka"
        << setw(12) << left << "Elektronnaya" << endl;
}

string StandardBook::getCoverType() const { return coverType; }
bool StandardBook::getHasEbook() const { return hasEbook; }

void StandardBook::setCoverType(const string &coverType) { this->coverType = coverType; }
void StandardBook::setHasEbook(bool hasEbook) { this->hasEbook = hasEbook; }

void StandardBook::edit()
{
    Book::edit();
    int choice;
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    do {
        cout << "1. Изменить тип обложки" << endl;
        cout << "2. Изменить наличие электронной версии" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        
        choice = numValidator.inputNumber(cin, 0, 2);
        
        switch(choice) {
            case 1: {
                cout << "Введите тип обложки: ";
                string coverType = validator.inputString("", cin);
                setCoverType(coverType);
                cout << "Тип обложки изменен" << endl;
                break;
            }
            case 2: {
                cout << "Есть электронная версия? (1-да, 0-нет): ";
                int hasEbook = numValidator.inputNumber(cin, 0, 1);
                cin.ignore();
                setHasEbook(hasEbook == 1);
                cout << "Наличие электронной версии изменено" << endl;
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

bool StandardBook::operator==(const StandardBook& other) const
{
    if (!(static_cast<const Book&>(*this) == static_cast<const Book&>(other)))
        return false;
    
    if (other.coverType != "" && this->coverType != other.coverType)
        return false;
    
    return true;
}

istream &operator>>(istream &in, StandardBook &obj)
{
    in >> static_cast<Book &>(obj);
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    cout << "Введите тип обложки: ";
    string coverType = validator.inputString("", in);
    obj.setCoverType(coverType);
    
    cout << "Есть электронная версия? (1-да, 0-нет): ";
    int hasEbook = numValidator.inputNumber(in, 0, 1);
    obj.setHasEbook(hasEbook == 1);
    
    return in;
}

istream &readFromFile(istream &in, StandardBook &obj)
{
    Book& base = static_cast<Book&>(obj);
    readFromFile(in, base);
    string coverType;
    bool hasEbook;
    in >> coverType >> hasEbook;
    obj.setCoverType(coverType);
    obj.setHasEbook(hasEbook);
    return in;
}

ostream &writeToFile(ostream &out, const StandardBook &obj)
{
    writeToFile(out, static_cast<const Book&>(obj));
    out << " " << obj.coverType << " " << obj.hasEbook;
    return out;
}

ostream &operator<<(ostream &out, StandardBook &obj)
{
    out << static_cast<Book &>(obj)
        << setw(15) << left << obj.coverType
        << setw(12) << left << (obj.hasEbook ? "Да" : "Нет");
    return out;
}

StandardBook &StandardBook::operator=(const StandardBook &other)
{
    if (this != &other)
    {
        Book::operator=(other);
        coverType = other.coverType;
        hasEbook = other.hasEbook;
    }
    return *this;
}