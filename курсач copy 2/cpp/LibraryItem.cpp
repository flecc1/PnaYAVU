// LibraryItem.cpp
#include "../headers/LibraryItem.h"
#include "../headers/excep_vvoda.h"

void LibraryItem::printHeader() const
{
    cout << setw(20) << left << "Nazvanie" 
        << setw(20) << left << "Avtor" 
        << setw(8) << left << "God"
        << setw(15) << left << "Zhanr"
        << setw(12) << left << "Kopii"
        << setw(10) << left << "Cena" << endl;
}

string LibraryItem::getTitle() const 
{ 
    return title; 
}
string LibraryItem::getAuthor() const 
{ 
    return author; 
}
int LibraryItem::getYear() const 
{ 
    return year; 
}
string LibraryItem::getGenre() const 
{ 
    return genre; 
}
int LibraryItem::getAvailableCopies() const 
{ 
    return availableCopies; 
}
double LibraryItem::getPrice() const 
{ 
    return price; 
}

void LibraryItem::setTitle(const string &title) 
{ 
    this->title = title; 
}
void LibraryItem::setAuthor(const string &author) 
{ 
    this->author = author; 
}
void LibraryItem::setYear(int year) 
{ 
    this->year = year; 
}
void LibraryItem::setGenre(const string &genre) 
{ 
    this->genre = genre; 
}
void LibraryItem::setAvailableCopies(int copies) 
{ 
    this->availableCopies = copies; 
}
void LibraryItem::setPrice(double price) 
{ 
    this->price = price; 
}

void LibraryItem::edit()
{
    int choice;
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    do {
        cout << "1. Изменить название" << endl;
        cout << "2. Изменить автора" << endl;
        cout << "3. Изменить год" << endl;
        cout << "4. Изменить жанр" << endl;
        cout << "5. Изменить количество копий" << endl;
        cout << "6. Изменить цену" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        
        choice = numValidator.inputNumber(cin, 0, 6);
        
        switch(choice) {
            case 1: {
                cout << "Введите название: ";
                string title = validator.inputString("", cin);
                setTitle(title);
                cout << "Название изменено" << endl;
                break;
            }
            case 2: {
                cout << "Введите автора: ";
                string author = validator.inputString("", cin);
                setAuthor(author);
                cout << "Автор изменен" << endl;
                break;
            }
            case 3: {
                cout << "Введите год: ";
                int year = numValidator.inputNumber(cin, 0, 3000);
                setYear(year);
                cout << "Год изменен" << endl;
                break;
            }
            case 4: {
                cout << "Введите жанр: ";
                string genre = validator.inputString("", cin);
                setGenre(genre);
                cout << "Жанр изменен" << endl;
                break;
            }
            case 5: {
                cout << "Введите количество копий: ";
                int copies = numValidator.inputNumber(cin, 0, 10000);
                setAvailableCopies(copies);
                cout << "Количество копий изменено" << endl;
                break;
            }
            case 6: {
                cout << "Введите цену: ";
                double price = numValidator.inputDouble(cin, 0.0, 1000000.0);
                setPrice(price);
                cout << "Цена изменена" << endl;
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

bool LibraryItem::operator==(const LibraryItem& other) const
{
    if (other.title != "" && this->title != other.title)
        return false;
    if (other.author != "" && this->author != other.author)
        return false;
    if (other.year != 0 && this->year != other.year)
        return false;
    if (other.genre != "" && this->genre != other.genre)
        return false;
    if (other.availableCopies != 0 && this->availableCopies != other.availableCopies)
        return false;
    if (other.price != 0.0 && this->price != other.price)
        return false;
    return true;
}

istream &operator>>(istream &in, LibraryItem &obj)
{
    Exp_vvoda validator;
    Exp_vvoda numValidator;
    
    // Очищаем буфер перед началом ввода
    if (in.peek() == '\n') {
        in.ignore();
    }
    
    cout << "введите название книги: ";
    string title = validator.inputString("", in);
    obj.setTitle(title);
    
    cout << "введите автора: ";
    string author = validator.inputString("", in);
    obj.setAuthor(author);
    
    cout << "введите год издания: ";
    int year = numValidator.inputNumber(in, 0, 3000);
    obj.setYear(year);
    
    cout << "введите жанр: ";
    string genre = validator.inputString("", in);
    obj.setGenre(genre);
    
    cout << "введите количество копий: ";
    int copies = numValidator.inputNumber(in, 0, 10000);
    obj.setAvailableCopies(copies);
    
    cout << "введите цену: ";
    double price = numValidator.inputDouble(in, 0.0, 1000000.0);
    obj.setPrice(price);
    
    return in;
}

istream &readFromFile(istream &in, LibraryItem &obj)
{
    string title, author, genre;
    int year, copies;
    double price;
    
    in >> title >> author >> year >> genre >> copies >> price;
    obj.setTitle(title);
    obj.setAuthor(author);
    obj.setYear(year);
    obj.setGenre(genre);
    obj.setAvailableCopies(copies);
    obj.setPrice(price);
    
    return in;
}

ostream &writeToFile(ostream &out, const LibraryItem &obj)
{
    out << obj.title << " " << obj.author << " " << obj.year << " " 
        << obj.genre << " " << obj.availableCopies << " " << obj.price;
    return out;
}

ostream &operator<<(ostream &out, LibraryItem &obj)
{
    out << setw(20) << left << obj.title 
        << setw(20) << left << obj.author
        << setw(8) << left << obj.year
        << setw(15) << left << obj.genre
        << setw(12) << left << obj.availableCopies
        << setw(10) << left << fixed << setprecision(2) << obj.price;
    return out;
}

LibraryItem &LibraryItem::operator=(const LibraryItem &other)
{
    if (this != &other)
    {
        title = other.title;
        author = other.author;
        year = other.year;
        genre = other.genre;
        availableCopies = other.availableCopies;
        price = other.price;
    }
    return *this;
}