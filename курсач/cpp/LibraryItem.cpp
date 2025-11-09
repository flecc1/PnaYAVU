// LibraryItem.cpp
#include "../headers/LibraryItem.h"

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

istream &operator>>(istream &in, LibraryItem &obj)
{
    cout << "введите название книги: ";
    getline(in, obj.title);
    cout << "введите автора: ";
    getline(in, obj.author);
    cout << "введите год издания: ";
    in >> obj.year;
    in.ignore();
    cout << "введите жанр: ";
    getline(in, obj.genre);
    cout << "введите количество копий: ";
    in >> obj.availableCopies;
    cout << "введите цену: ";
    in >> obj.price;
    in.ignore();
    return in;
}

ostream &operator<<(ostream &out, LibraryItem &obj)
{
    out << obj.title << obj.author
        << obj.year << obj.genre
        << obj.availableCopies
        << obj.price;
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