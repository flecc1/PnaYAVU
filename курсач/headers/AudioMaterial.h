// AudioMaterial.h
#ifndef AUDIOMATERIAL_H
#define AUDIOMATERIAL_H

#include "LibraryItem.h"
#include <iomanip>

class AudioMaterial : public LibraryItem
{
protected:
    int duration;
    string format;
public:
    AudioMaterial() : LibraryItem(), duration(0), format("") {}
    AudioMaterial(const string& title, const string& author, int year, const string& genre, int availableCopies, double price,
                  int duration, const string& format)
        : LibraryItem(title, author, year, genre, availableCopies, price), duration(duration), format(format) {}
    AudioMaterial(const AudioMaterial& other) : LibraryItem(other), duration(other.duration), format(other.format) {}
    ~AudioMaterial() {}
    
    void printHeader() const override;
    
    int getDuration() const;
    string getFormat() const;
    
    void setDuration(int duration);
    void setFormat(const string& format);
    
    void edit() override;
    
    bool operator==(const AudioMaterial& other) const;
    
    friend istream& operator>>(istream& in, AudioMaterial& obj);
    friend ostream& operator<<(ostream& out, AudioMaterial& obj);
    friend istream& readFromFile(istream& in, AudioMaterial& obj);
    friend ostream& writeToFile(ostream& out, const AudioMaterial& obj);
    AudioMaterial& operator=(const AudioMaterial& other);
};

#endif