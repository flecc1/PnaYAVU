// Book.cpp
#include "../headers/Book.h"

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

istream &operator>>(istream &in, Book &obj)
{
    in >> static_cast<LibraryItem &>(obj);
    cout << "Enter pages: ";
    in >> obj.pages;
    in.ignore();
    cout << "введите ISBN: ";
    getline(in, obj.isbn);
    cout << "введите публикатора: ";
    getline(in, obj.publisher);
    return in;
}

ostream &operator<<(ostream &out, Book &obj)
{
    out << static_cast<LibraryItem &>(obj)
        << obj.pages << obj.isbn << obj.publisher;
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
    }
    return *this;
}