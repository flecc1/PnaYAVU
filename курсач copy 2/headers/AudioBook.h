// AudioBook.h
#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "AudioMaterial.h"
#include <iomanip>

/**
 * @class AudioBook
 * @brief Класс аудиокниги, наследуется от AudioMaterial
 * 
 * Представляет аудиокнигу с дополнительными характеристиками:
 * количество глав и имя диктора/чтеца.
 * Наследует все свойства аудиоматериала и добавляет специфичные для аудиокниг поля.
 */
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

    void printHeader() const override;

    int getChapters() const;
    string getNarrator() const;

    void setChapters(int chapters);
    void setNarrator(const string &narrator);

    void edit() override;
    
    bool operator==(const AudioBook& other) const;
    
    friend istream &operator>>(istream &in, AudioBook &obj);
    friend ostream &operator<<(ostream &out, AudioBook &obj);
    friend istream &readFromFile(istream &in, AudioBook &obj);
    friend ostream &writeToFile(ostream &out, const AudioBook &obj);
    AudioBook &operator=(const AudioBook &other);
};

#endif