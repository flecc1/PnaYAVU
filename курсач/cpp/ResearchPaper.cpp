// ResearchPaper.cpp
#include "../headers/ResearchPaper.h"

string ResearchPaper::getField() const { return field; }
bool ResearchPaper::getIsReviewed() const { return isReviewed; }
int ResearchPaper::getCitations() const { return citations; }

void ResearchPaper::setField(const string &field) { this->field = field; }
void ResearchPaper::setIsReviewed(bool isReviewed) { this->isReviewed = isReviewed; }
void ResearchPaper::setCitations(int citations) { this->citations = citations; }

istream &operator>>(istream &in, ResearchPaper &obj)
{
    in >> static_cast<Book &>(obj);
    cout << "Enter field: ";
    getline(in, obj.field);
    cout << "Is reviewed (0/1): ";
    in >> obj.isReviewed;
    cout << "Enter citations: ";
    in >> obj.citations;
    in.ignore();
    return in;
}

ostream &operator<<(ostream &out, ResearchPaper &obj)
{
    out << static_cast<Book &>(obj)
        << "\nField: " << obj.field << "\nPeer Reviewed: " << (obj.isReviewed ? "Yes" : "No")
        << "\nCitations: " << obj.citations;
    return out;
}

ResearchPaper &ResearchPaper::operator=(const ResearchPaper &other)
{
    if (this != &other)
    {
        Book::operator=(other);
        field = other.field;
        isReviewed = other.isReviewed;
        citations = other.citations;
    }
    return *this;
}