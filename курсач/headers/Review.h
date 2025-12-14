#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * @class Review
 * @brief Класс рецензии на книгу
 * 
 * Представляет рецензию с информацией об авторе рецензии,
 * тексте рецензии и оценке.
 */
class Review
{
private:
    string reviewerName;  // Имя автора рецензии
    string text;          // Текст рецензии
    int rating;           // Оценка от 1 до 5

public:
    Review() : reviewerName(""), text(""), rating(0) {}
    Review(const string& reviewerName, const string& text, int rating)
        : reviewerName(reviewerName), text(text), rating(rating) {}
    Review(const Review& other)
        : reviewerName(other.reviewerName), text(other.text), rating(other.rating) {}
    ~Review() {}
    
    string getReviewerName() const;
    string getText() const;
    int getRating() const;
    
    void setReviewerName(const string& reviewerName);
    void setText(const string& text);
    void setRating(int rating);
    
    void edit();
    void printHeader() const;
    
    bool operator==(const Review& other) const;
    
    friend istream& operator>>(istream& in, Review& obj);
    friend ostream& operator<<(ostream& out, const Review& obj);
    friend istream& readFromFile(istream& in, Review& obj);
    friend ostream& writeToFile(ostream& out, const Review& obj);
    Review& operator=(const Review& other);
};

#endif

