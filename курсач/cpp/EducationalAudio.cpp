// EducationalAudio.cpp
#include "../headers/EducationalAudio.h"

string EducationalAudio::getInstructor() const 
{ 
    return instructor;
}
string EducationalAudio::getSubject() const 
{ 
    return subject; 
}

void EducationalAudio::setInstructor(const string &instructor) 
{ 
    this->instructor = instructor; 
}
void EducationalAudio::setSubject(const string &subject) 
{ 
    this->subject = subject; 
}

istream &operator>>(istream &in, EducationalAudio &obj)
{
    in >> static_cast<AudioMaterial &>(obj);
    cout << "введите инструктор: ";
    getline(in, obj.instructor);
    cout << "ввидите предмет: ";
    getline(in, obj.subject);
    return in;
}

ostream &operator<<(ostream &out, EducationalAudio &obj)
{
    out << static_cast<AudioMaterial &>(obj)
        << obj.instructor << obj.subject;
    return out;
}

EducationalAudio &EducationalAudio::operator=(const EducationalAudio &other)
{
    if (this != &other)
    {
        AudioMaterial::operator=(other);
        instructor = other.instructor;
        subject = other.subject;
    }
    return *this;
}