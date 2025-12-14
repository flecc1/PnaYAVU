// EducationalAudio.h
#ifndef EDUCATIONALAUDIO_H
#define EDUCATIONALAUDIO_H

#include "AudioMaterial.h"
#include <iomanip>

/**
 * @class EducationalAudio
 * @brief Класс образовательного аудиоматериала, наследуется от AudioMaterial
 * 
 * Представляет образовательный аудиокурс или лекцию с характеристиками:
 * имя преподавателя/инструктора и предмет/дисциплина.
 * Наследует все свойства аудиоматериала и добавляет образовательную специфику.
 */
class EducationalAudio : public AudioMaterial
{
    string instructor;
    string subject;

public:
    EducationalAudio() : AudioMaterial(), instructor(""), subject("") {}
    EducationalAudio(const string &title, const string &author, int year, const string &genre, int availableCopies, double price,
                     int duration, const string &format, const string &instructor, const string &subject)
        : AudioMaterial(title, author, year, genre, availableCopies, price, duration, format), instructor(instructor), subject(subject) {}
    EducationalAudio(const EducationalAudio &other) : AudioMaterial(other), instructor(other.instructor), subject(other.subject) {}
    ~EducationalAudio() {}

    void printHeader() const override;

    string getInstructor() const;
    string getSubject() const;

    void setInstructor(const string &instructor);
    void setSubject(const string &subject);

    void edit() override;
    
    bool operator==(const EducationalAudio& other) const;
    
    friend istream &operator>>(istream &in, EducationalAudio &obj);
    friend ostream &operator<<(ostream &out, EducationalAudio &obj);
    friend istream &readFromFile(istream &in, EducationalAudio &obj);
    friend ostream &writeToFile(ostream &out, const EducationalAudio &obj);
    EducationalAudio &operator=(const EducationalAudio &other);
};

#endif