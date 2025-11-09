// AudioMaterial.cpp
#include "../headers/AudioMaterial.h"

int AudioMaterial::getDuration() const 
{ 
    return duration; 
}
string AudioMaterial::getFormat() const 
{ 
    return format; 
}

void AudioMaterial::setDuration(int duration) 
{ 
    this->duration = duration; 
}
void AudioMaterial::setFormat(const string &format) 
{ 
    this->format = format; 
}

istream &operator>>(istream &in, AudioMaterial &obj)
{
    in >> static_cast<LibraryItem &>(obj);
    cout << "введите длительность (мин): ";
    in >> obj.duration;
    in.ignore();
    cout << "введите формат: ";
    getline(in, obj.format);
    return in;
}

ostream &operator<<(ostream &out, AudioMaterial &obj)
{
    out << static_cast<LibraryItem &>(obj)
        << obj.duration << obj.format;
    return out;
}

AudioMaterial &AudioMaterial::operator=(const AudioMaterial &other)
{
    if (this != &other)
    {
        LibraryItem::operator=(other);
        duration = other.duration;
        format = other.format;
    }
    return *this;
}