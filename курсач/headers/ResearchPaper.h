// ResearchPaper.h
#ifndef RESEARCHPAPER_H
#define RESEARCHPAPER_H

#include "Book.h"
#include <iomanip>

class ResearchPaper : public Book
{
    string field;
    bool isReviewed;
    int citations;

public:
    ResearchPaper() : Book(), field(""), isReviewed(false), citations(0) {}
    ResearchPaper(const string &title, const string &author, int year, const string &genre, int availableCopies, double price,
                  int pages, const string &isbn, const string &publisher, const string &field, bool isReviewed, int citations)
        : Book(title, author, year, genre, availableCopies, price, pages, isbn, publisher), field(field), isReviewed(isReviewed), citations(citations) {}
    ResearchPaper(const ResearchPaper &other) : Book(other), field(other.field), isReviewed(other.isReviewed), citations(other.citations) {}
    ~ResearchPaper() {}

    void printHeader() const override;

    string getField() const;
    bool getIsReviewed() const;
    int getCitations() const;

    void setField(const string &field);
    void setIsReviewed(bool isReviewed);
    void setCitations(int citations);

    void edit() override;
    
    bool operator==(const ResearchPaper& other) const;
    
    friend istream &operator>>(istream &in, ResearchPaper &obj);
    friend ostream &operator<<(ostream &out, ResearchPaper &obj);
    friend istream &readFromFile(istream &in, ResearchPaper &obj);
    friend ostream &writeToFile(ostream &out, const ResearchPaper &obj);
    ResearchPaper &operator=(const ResearchPaper &other);
};

#endif