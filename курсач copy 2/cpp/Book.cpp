// Book.cpp
#include "../headers/Book.h"
#include "../headers/excep_vvoda.h"
#include "../headers/Review.h"
#include <iomanip>
#include <string>

void Book::printHeader() const
{
    cout << setw(20) << left << "Nazvanie" 
        << setw(20) << left << "Avtor" 
        << setw(8) << left << "God"
        << setw(15) << left << "Zhanr"
        << setw(12) << left << "Kopii"
        << setw(10) << left << "Cena"
        << setw(8) << left << "Stranic"
        << setw(15) << left << "ISBN"
        << setw(20) << left << "Izdatelstvo" << endl;
}

int Book::getPages() const 
{ 
    return pages; 
}
string Book::getIsbn() const 
{
    return isbn; 
}
string Book::getPublisher() const 
{ 
    return publisher;
}

void Book::setPages(int pages) 
{ 
    this->pages = pages;
}
void Book::setIsbn(const string &isbn) 
{ 
    this->isbn = isbn; 
}
void Book::setPublisher(const string &publisher) 
{ 
    this->publisher = publisher; 
}

void Book::addReview(const Review& review)
{
    reviews.pushback(review);
}

void Book::removeReview(int index)
{
    if (index >= 0 && index < reviews.getSize())
    {
        reviews.remove_by_index(index);
    }
}

void Book::displayAllReviews() const
{
    if (reviews.is_empty())
    {
        cout << "Recenzii dlya etoy knigi poka net." << endl;
        return;
    }
    
    cout << "\n=== RECENZII NA KNIGU: " << getTitle() << " ===" << endl;
    Review temp;
    temp.printHeader();
    cout << reviews << endl;
    
    double avgRating = getAverageRating();
    if (avgRating > 0)
    {
        cout << "\nSrednyaya ocenka: " << fixed << setprecision(2) << avgRating << endl;
    }
}

int Book::getReviewCount() const
{
    return reviews.getSize();
}

Ochered<Review>& Book::getReviews()
{
    return reviews;
}

const Ochered<Review>& Book::getReviews() const
{
    return reviews;
}

double Book::getAverageRating() const
{
    if (reviews.is_empty())
        return 0.0;
    
    int totalRating = 0;
    for (int i = 0; i < reviews.getSize(); i++)
    {
        const Review& review = reviews[i];
        totalRating += review.getRating();
    }
    
    return static_cast<double>(totalRating) / reviews.getSize();
}

void Book::edit()
{
    LibraryItem::edit();
    int choice;
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    do {
        cout << "1. Изменить количество страниц" << endl;
        cout << "2. Изменить ISBN" << endl;
        cout << "3. Изменить издательство" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        
        choice = numValidator.inputNumber(cin, 0, 3);
        
        switch(choice) {
            case 1: {
                cout << "Введите количество страниц: ";
                int pages = numValidator.inputNumber(cin, 1, 10000);
                setPages(pages);
                cout << "Количество страниц изменено" << endl;
                break;
            }
            case 2: {
                cout << "Введите ISBN: ";
                string isbn = validator.inputString("", cin);
                setIsbn(isbn);
                cout << "ISBN изменен" << endl;
                break;
            }
            case 3: {
                cout << "Введите издательство: ";
                string publisher = validator.inputString("", cin);
                setPublisher(publisher);
                cout << "Издательство изменено" << endl;
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

bool Book::operator==(const Book& other) const
{
    if (!(static_cast<const LibraryItem&>(*this) == static_cast<const LibraryItem&>(other)))
        return false;
    
    if (other.pages != 0 && this->pages != other.pages)
        return false;
    if (other.isbn != "" && this->isbn != other.isbn)
        return false;
    if (other.publisher != "" && this->publisher != other.publisher)
        return false;
    
    return true;
}

istream &operator>>(istream &in, Book &obj)
{
    in >> static_cast<LibraryItem &>(obj);
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    cout << "Введите количество страниц: ";
    int pages = numValidator.inputNumber(in, 1, 10000);
    obj.setPages(pages);
    
    cout << "введите ISBN: ";
    string isbn = validator.inputString("", in);
    obj.setIsbn(isbn);
    
    cout << "введите издательство: ";
    string publisher = validator.inputString("", in);
    obj.setPublisher(publisher);
    
    return in;
}

istream &readFromFile(istream &in, Book &obj)
{
    LibraryItem& base = static_cast<LibraryItem&>(obj);
    readFromFile(in, base);
    int pages;
    string isbn, publisher;
    in >> pages >> isbn >> publisher;
    obj.setPages(pages);
    obj.setIsbn(isbn);
    obj.setPublisher(publisher);
    
    // Читаем количество рецензий
    int reviewCount;
    in >> reviewCount;
    in.ignore();
    
    // Читаем рецензии
    for (int i = 0; i < reviewCount; i++)
    {
        Review review;
        readFromFile(in, review);
        obj.addReview(review);
    }
    
    return in;
}

ostream &writeToFile(ostream &out, const Book &obj)
{
    writeToFile(out, static_cast<const LibraryItem&>(obj));
    out << " " << obj.pages << " " << obj.isbn << " " << obj.publisher;
    
    // Записываем количество рецензий
    out << " " << obj.reviews.getSize();
    
    // Записываем рецензии
    for (int i = 0; i < obj.reviews.getSize(); i++)
    {
        const Review& review = obj.reviews[i];
        out << " ";
        writeToFile(out, review);
    }
    
    return out;
}

ostream &operator<<(ostream &out, Book &obj)
{
    out << static_cast<LibraryItem &>(obj)
        << setw(8) << left << obj.pages
        << setw(15) << left << obj.isbn
        << setw(20) << left << obj.publisher;
    return out;
}

Book &Book::operator=(const Book &other)
{
    if (this != &other)
    {
        LibraryItem::operator=(other);
        pages = other.pages;
        isbn = other.isbn;
        publisher = other.publisher;
        reviews = other.reviews;
    }
    return *this;
}