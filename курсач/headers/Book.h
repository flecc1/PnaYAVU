// Book.h
#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book : public LibraryItem
{
protected:
    int pages;
    string isbn;
    string publisher;

public:
    Book() : LibraryItem(), pages(0), isbn(""), publisher("") {}
    Book(const string &title, const string &author, int year, const string &genre, int availableCopies, double price,
         int pages, const string &isbn, const string &publisher)
        : LibraryItem(title, author, year, genre, availableCopies, price), pages(pages), isbn(isbn), publisher(publisher) {}
    Book(const Book &other) : LibraryItem(other), pages(other.pages), isbn(other.isbn), publisher(other.publisher) {}
    ~Book() {}

    int getPages() const;
    string getIsbn() const;
    string getPublisher() const;

    void setPages(int pages);
    void setIsbn(const string &isbn);
    void setPublisher(const string &publisher);

    friend istream &operator>>(istream &in, Book &obj);
    friend ostream &operator<<(ostream &out, Book &obj);
    Book &operator=(const Book &other);
};

#endif