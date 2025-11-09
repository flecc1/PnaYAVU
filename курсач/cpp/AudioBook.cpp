// AudioBook.cpp
#include "../headers/AudioBook.h"

int AudioBook::getChapters() const { return chapters; }
string AudioBook::getNarrator() const { return narrator; }

void AudioBook::setChapters(int chapters) { this->chapters = chapters; }
void AudioBook::setNarrator(const string &narrator) { this->narrator = narrator; }

istream &operator>>(istream &in, AudioBook &obj)
{
    in >> static_cast<AudioMaterial &>(obj);
    cout << "Enter chapters: ";
    in >> obj.chapters;
    in.ignore();
    cout << "Enter narrator: ";
    getline(in, obj.narrator);
    return in;
}

ostream &operator<<(ostream &out, AudioBook &obj)
{
    out << static_cast<AudioMaterial &>(obj)
        << obj.chapters << obj.narrator;
    return out;
}

AudioBook &AudioBook::operator=(const AudioBook &other)
{
    if (this != &other)
    {
        AudioMaterial::operator=(other);
        chapters = other.chapters;
        narrator = other.narrator;
    }
    return *this;
}