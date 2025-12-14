#include "../headers/Review.h"
#include "../headers/excep_vvoda.h"
#include <sstream>
#include <iomanip>

string Review::getReviewerName() const
{
    return reviewerName;
}

string Review::getText() const
{
    return text;
}

int Review::getRating() const
{
    return rating;
}

void Review::setReviewerName(const string& reviewerName)
{
    this->reviewerName = reviewerName;
}

void Review::setText(const string& text)
{
    this->text = text;
}

void Review::setRating(int rating)
{
    this->rating = rating;
}

void Review::printHeader() const
{
    cout << setw(20) << left << "Avtor recenzii"
         << setw(8) << left << "Ocenka"
         << setw(50) << left << "Tekst recenzii" << endl;
}

void Review::edit()
{
    int choice;
    Exp_vvoda numValidator;
    Exp_vvoda validator;
    
    do {
        cout << "1. Изменить имя автора рецензии" << endl;
        cout << "2. Изменить текст рецензии" << endl;
        cout << "3. Изменить оценку" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        
        choice = numValidator.inputNumber(cin, 0, 3);
        
        switch(choice) {
            case 1: {
                cout << "Введите имя автора рецензии: ";
                string name = validator.inputString("", cin);
                setReviewerName(name);
                cout << "Имя автора изменено" << endl;
                break;
            }
            case 2: {
                cout << "Введите текст рецензии: ";
                string reviewText = validator.inputString("", cin);
                setText(reviewText);
                cout << "Текст рецензии изменен" << endl;
                break;
            }
            case 3: {
                cout << "Введите оценку (1-5): ";
                int reviewRating = numValidator.inputNumber(cin, 1, 5);
                setRating(reviewRating);
                cout << "Оценка изменена" << endl;
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

bool Review::operator==(const Review& other) const
{
    if (other.reviewerName != "" && this->reviewerName != other.reviewerName)
        return false;
    if (other.text != "" && this->text != other.text)
        return false;
    if (other.rating != 0 && this->rating != other.rating)
        return false;
    return true;
}

istream& operator>>(istream& in, Review& obj)
{
    Exp_vvoda validator;
    Exp_vvoda numValidator;
    
    // Очищаем буфер перед началом ввода
    if (in.peek() == '\n') {
        in.ignore();
    }
    
    cout << "Введите имя автора рецензии: ";
    string name = validator.inputString("", in);
    obj.setReviewerName(name);
    
    cout << "Введите текст рецензии: ";
    string text = validator.inputString("", in);
    obj.setText(text);
    
    cout << "Введите оценку (1-5): ";
    int rating = numValidator.inputNumber(in, 1, 5);
    obj.setRating(rating);
    
    return in;
}

ostream& operator<<(ostream& out, Review& obj)
{
    out << setw(20) << left << obj.reviewerName
        << setw(8) << left << obj.rating
        << setw(50) << left << (obj.text.length() > 47 ? obj.text.substr(0, 47) + "..." : obj.text);
    return out;
}

istream& readFromFile(istream& in, Review& obj)
{
    string reviewerName, text;
    int rating;
    
    in >> reviewerName >> rating;
    in.ignore(); // Пропускаем пробел перед текстом
    getline(in, text);
    
    obj.setReviewerName(reviewerName);
    obj.setRating(rating);
    obj.setText(text);
    
    return in;
}

ostream& writeToFile(ostream& out, const Review& obj)
{
    out << obj.reviewerName << " " << obj.rating << " " << obj.text;
    return out;
}

Review& Review::operator=(const Review& other)
{
    if (this != &other)
    {
        reviewerName = other.reviewerName;
        text = other.text;
        rating = other.rating;
    }
    return *this;
}

