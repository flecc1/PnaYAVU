// Book.h
#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include "Review.h"
#include "ochered.h"
#include <iomanip>
#include <vector>


class Book : public LibraryItem
{
protected:
    int pages;
    string isbn;
    string publisher;
    Ochered<Review> reviews;  // Контейнер рецензий для книги

public:
    Book() : LibraryItem(), pages(0), isbn(""), publisher("") {}
    Book(const string &title, const string &author, int year, const string &genre, int availableCopies, double price,
         int pages, const string &isbn, const string &publisher)
        : LibraryItem(title, author, year, genre, availableCopies, price), pages(pages), isbn(isbn), publisher(publisher) {}
    Book(const Book &other) : LibraryItem(other), pages(other.pages), isbn(other.isbn), publisher(other.publisher) {}
    ~Book() {}

    void printHeader() const override;

    int getPages() const;
    string getIsbn() const;
    string getPublisher() const;

    void setPages(int pages);
    void setIsbn(const string &isbn);
    void setPublisher(const string &publisher);
    
    // Методы для работы с рецензиями
    void addReview(const Review& review);
    void removeReview(int index);
    void displayAllReviews() const;
    int getReviewCount() const;
    Ochered<Review>& getReviews();
    const Ochered<Review>& getReviews() const;
    double getAverageRating() const;

    void edit() override;
    
    bool operator==(const Book& other) const;

    friend istream &operator>>(istream &in, Book &obj);
    friend ostream &operator<<(ostream &out, Book &obj);
    friend istream &readFromFile(istream &in, Book &obj);
    friend ostream &writeToFile(ostream &out, const Book &obj);
    Book &operator=(const Book &other);
};

#endif