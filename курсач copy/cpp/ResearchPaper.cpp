// ResearchPaper.cpp
#include "../headers/ResearchPaper.h"
#include "../headers/excep_vvoda.h"

void ResearchPaper::printHeader() const
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
        << setw(20) << left << "Oblast"
        << setw(15) << left << "Recenzirovano"
        << setw(12) << left << "Citirovaniya" << endl;
}

string ResearchPaper::getField() const { return field; }
bool ResearchPaper::getIsReviewed() const { return isReviewed; }
int ResearchPaper::getCitations() const { return citations; }

void ResearchPaper::setField(const string &field) { this->field = field; }
void ResearchPaper::setIsReviewed(bool isReviewed) { this->isReviewed = isReviewed; }
void ResearchPaper::setCitations(int citations) { this->citations = citations; }

void ResearchPaper::edit()
{
    Book::edit();
    int choice;
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    do {
        cout << "1. Изменить область" << endl;
        cout << "2. Изменить статус рецензирования" << endl;
        cout << "3. Изменить количество цитирований" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        
        choice = numValidator.inputNumber(cin, 0, 3);
        
        switch(choice) {
            case 1: {
                cout << "Введите область: ";
                string field = validator.inputString("", cin);
                setField(field);
                cout << "Область изменена" << endl;
                break;
            }
            case 2: {
                cout << "Рецензировано? (1-да, 0-нет): ";
                int isReviewed = numValidator.inputNumber(cin, 0, 1);
                setIsReviewed(isReviewed == 1);
                cout << "Статус рецензирования изменен" << endl;
                break;
            }
            case 3: {
                cout << "Введите количество цитирований: ";
                int citations = numValidator.inputNumber(cin, 0, 100000);
                setCitations(citations);
                cout << "Количество цитирований изменено" << endl;
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

bool ResearchPaper::operator==(const ResearchPaper& other) const
{
    if (!(static_cast<const Book&>(*this) == static_cast<const Book&>(other)))
        return false;
    
    if (other.field != "" && this->field != other.field)
        return false;
    
    return true;
}

istream &operator>>(istream &in, ResearchPaper &obj)
{
    in >> static_cast<Book &>(obj);
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    cout << "Введите область: ";
    string field = validator.inputString("", in);
    obj.setField(field);
    
    cout << "Рецензировано? (1-да, 0-нет): ";
    int isReviewed = numValidator.inputNumber(in, 0, 1);
    obj.setIsReviewed(isReviewed == 1);
    
    cout << "Введите количество цитирований: ";
    int citations = numValidator.inputNumber(in, 0, 100000);
    obj.setCitations(citations);
    
    return in;
}

istream &readFromFile(istream &in, ResearchPaper &obj)
{
    Book& base = static_cast<Book&>(obj);
    readFromFile(in, base);
    string field;
    bool isReviewed;
    int citations;
    in >> field >> isReviewed >> citations;
    obj.setField(field);
    obj.setIsReviewed(isReviewed);
    obj.setCitations(citations);
    return in;
}

ostream &writeToFile(ostream &out, const ResearchPaper &obj)
{
    writeToFile(out, static_cast<const Book&>(obj));
    out << " " << obj.field << " " << obj.isReviewed << " " << obj.citations;
    return out;
}

ostream &operator<<(ostream &out, ResearchPaper &obj)
{
    out << static_cast<Book &>(obj)
        << setw(20) << left << obj.field
        << setw(15) << left << (obj.isReviewed ? "Да" : "Нет")
        << setw(12) << left << obj.citations;
    return out;
}

ResearchPaper &ResearchPaper::operator=(const ResearchPaper &other)
{
    if (this != &other)
    {
        Book::operator=(other);
        field = other.field;
        isReviewed = other.isReviewed;
        citations = other.citations;
    }
    return *this;
}