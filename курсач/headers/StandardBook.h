// StandardBook.h
#ifndef STANDARDBOOK_H
#define STANDARDBOOK_H

#include "Book.h"
#include <iomanip>


class StandardBook : public Book
{
    string coverType;
    bool hasEbook;

public:
    StandardBook() : Book(), coverType(""), hasEbook(false) {}
    StandardBook(const string &title, const string &author, int year, const string &genre, int availableCopies, double price,
                 int pages, const string &isbn, const string &publisher, const string &coverType, bool hasEbook)
        : Book(title, author, year, genre, availableCopies, price, pages, isbn, publisher), coverType(coverType), hasEbook(hasEbook) {}
    StandardBook(const StandardBook &other) : Book(other), coverType(other.coverType), hasEbook(other.hasEbook) {}
    ~StandardBook() {}

    void printHeader() const override;

    string getCoverType() const;
    bool getHasEbook() const;

    void setCoverType(const string &coverType);
    void setHasEbook(bool hasEbook);

    void edit() override;
    
    bool operator==(const StandardBook& other) const;

    friend istream &operator>>(istream &in, StandardBook &obj);
    friend ostream &operator<<(ostream &out, StandardBook &obj);
    friend istream &readFromFile(istream &in, StandardBook &obj);
    friend ostream &writeToFile(ostream &out, const StandardBook &obj);
    StandardBook &operator=(const StandardBook &other);
};

#endif