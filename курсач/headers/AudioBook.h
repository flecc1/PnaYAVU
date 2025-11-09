// AudioBook.h
#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "AudioMaterial.h"

class AudioBook : public AudioMaterial
{
    int chapters;
    string narrator;

public:
    AudioBook() : AudioMaterial(), chapters(0), narrator("") {}
    AudioBook(const string &title, const string &author, int year, const string &genre, int availableCopies, double price,
              int duration, const string &format, int chapters, const string &narrator)
        : AudioMaterial(title, author, year, genre, availableCopies, price, duration, format), chapters(chapters), narrator(narrator) {}
    AudioBook(const AudioBook &other) : AudioMaterial(other), chapters(other.chapters), narrator(other.narrator) {}
    ~AudioBook() {}

    int getChapters() const;
    string getNarrator() const;

    void setChapters(int chapters);
    void setNarrator(const string &narrator);

    friend istream &operator>>(istream &in, AudioBook &obj);
    friend ostream &operator<<(ostream &out, AudioBook &obj);
    AudioBook &operator=(const AudioBook &other);
};

#endif