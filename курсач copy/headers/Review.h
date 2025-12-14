#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

/**
 * @class Review
 * @brief Класс рецензии на книгу
 * 
 * Представляет рецензию с информацией об авторе рецензии,
 * тексте рецензии, дате написания и оценке.
 */
class Review
{
private:
    string reviewerName;  // Имя автора рецензии
    string text;          // Текст рецензии
    string date;          // Дата написания рецензии
    int rating;           // Оценка от 1 до 5

public:
    Review() : reviewerName(""), text(""), date(""), rating(0) {}
    Review(const string& reviewerName, const string& text, const string& date, int rating)
        : reviewerName(reviewerName), text(text), date(date), rating(rating) {}
    Review(const Review& other)
        : reviewerName(other.reviewerName), text(other.text), date(other.date), rating(other.rating) {}
    ~Review() {}
    
    string getReviewerName() const;
    string getText() const;
    string getDate() const;
    int getRating() const;
    
    void setReviewerName(const string& reviewerName);
    void setText(const string& text);
    void setDate(const string& date);
    void setRating(int rating);
    
    void edit();
    
    bool operator==(const Review& other) const;
    
    friend istream& operator>>(istream& in, Review& obj);
    friend ostream& operator<<(ostream& out, Review& obj);
    friend istream& readFromFile(istream& in, Review& obj);
    friend ostream& writeToFile(ostream& out, const Review& obj);
    Review& operator=(const Review& other);
    
    static string getCurrentDate();
};

#endif

