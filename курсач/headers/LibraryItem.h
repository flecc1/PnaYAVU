// LibraryItem.h
#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>
#include <string>

using namespace std;

class LibraryItem
{
protected:
    string title;
    string author;
    int year;
    string genre;
    int availableCopies;
    double price;
public:
    LibraryItem() : title(""), author(""), year(0), genre(""), availableCopies(0), price(0.0) {}
    LibraryItem(const string& title, const string& author, int year, const string& genre, int availableCopies, double price)
 : title(title), author(author), year(year), genre(genre), availableCopies(availableCopies), price(price) {}
    LibraryItem(const LibraryItem& other)
        : title(other.title), author(other.author), year(other.year), genre(other.genre), availableCopies(other.availableCopies), price(other.price) {}
    ~LibraryItem() {}
    
    string getTitle() const;
    string getAuthor() const;
    int getYear() const;
    string getGenre() const;
    int getAvailableCopies() const;
    double getPrice() const;
    
    void setTitle(const string& title);
    void setAuthor(const string& author);
    void setYear(int year);
    void setGenre(const string& genre);
    void setAvailableCopies(int copies);
    void setPrice(double price);
    
    friend istream& operator>>(istream& in, LibraryItem& obj);
    friend ostream& operator<<(ostream& out, LibraryItem& obj);
    LibraryItem& operator=(const LibraryItem& other);
};

#endif