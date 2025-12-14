// LibraryItem.h
#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * @class LibraryItem
 * @brief Базовый класс для элементов библиотеки
 * 
 * Представляет общие характеристики всех элементов библиотеки:
 * название, автор, год издания, жанр, количество доступных копий и цена.
 * Является родительским классом для всех типов библиотечных материалов.
 */
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
    virtual ~LibraryItem() {}
    
    virtual void printHeader() const;
    
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
    
    virtual void edit();
    
    bool operator==(const LibraryItem& other) const;
    
    friend istream& operator>>(istream& in, LibraryItem& obj);
    friend ostream& operator<<(ostream& out, LibraryItem& obj);
    friend istream& readFromFile(istream& in, LibraryItem& obj);
    friend ostream& writeToFile(ostream& out, const LibraryItem& obj);
    LibraryItem& operator=(const LibraryItem& other);
};

#endif