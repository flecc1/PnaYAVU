// EducationalAudio.h
#ifndef EDUCATIONALAUDIO_H
#define EDUCATIONALAUDIO_H

#include "AudioMaterial.h"

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

    string getInstructor() const;
    string getSubject() const;

    void setInstructor(const string &instructor);
    void setSubject(const string &subject);

    friend istream &operator>>(istream &in, EducationalAudio &obj);
    friend ostream &operator<<(ostream &out, EducationalAudio &obj);
    EducationalAudio &operator=(const EducationalAudio &other);
};

#endif