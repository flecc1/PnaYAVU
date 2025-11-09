// StandardBook.cpp
#include "../headers/StandardBook.h"

string StandardBook::getCoverType() const { return coverType; }
bool StandardBook::getHasEbook() const { return hasEbook; }

void StandardBook::setCoverType(const string &coverType) { this->coverType = coverType; }
void StandardBook::setHasEbook(bool hasEbook) { this->hasEbook = hasEbook; }

istream &operator>>(istream &in, StandardBook &obj)
{
    in >> static_cast<Book &>(obj);
    cout << "Enter cover type: ";
    getline(in, obj.coverType);
    cout << "Has ebook (0/1): ";
    in >> obj.hasEbook;
    in.ignore();
    return in;
}

ostream &operator<<(ostream &out, StandardBook &obj)
{
    out << static_cast<Book &>(obj)
        << "\nCover Type: " << obj.coverType << "\nHas Ebook: " << (obj.hasEbook ? "Yes" : "No");
    return out;
}

StandardBook &StandardBook::operator=(const StandardBook &other)
{
    if (this != &other)
    {
        Book::operator=(other);
        coverType = other.coverType;
        hasEbook = other.hasEbook;
    }
    return *this;
}