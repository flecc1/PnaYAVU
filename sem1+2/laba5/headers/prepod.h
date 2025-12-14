#ifndef PREPOD_H
#define PREPOD_H
#define M 80

#include "human.h"
class Prepod:virtual public Human
{
    protected:
    char dolgnost[M];
    char specialnost[M];
    char truds[M];
    public:
    Prepod():Human()
    {
        dolgnost[0] = '\0';
        specialnost[0] = '\0';
        truds[0] = '\0';
    }
    Prepod(const char* name, const char* sname, int age, const char* dolgnost, const char* specialnost, const char* truds):Human(name, sname, age)
    {
        strncpy(this->dolgnost, dolgnost, M);
        strncpy(this->specialnost, specialnost, M);
        strncpy(this->truds, truds, M);
        this->dolgnost[M - 1] = '\0';
        this->specialnost[M - 1] = '\0';
        this->truds[M - 1] = '\0';
    }
    Prepod(const Prepod& other) : Human(other)
    {
        strncpy(this->dolgnost, other.dolgnost, M - 1);
        strncpy(this->specialnost, other.specialnost, M - 1);
        strncpy(this->truds, other.truds, M - 1);
        this->dolgnost[M - 1] = '\0';
        this->specialnost[M - 1] = '\0';
        this->truds[M - 1] = '\0';
    }
    ~Prepod()
    {

    }
    public:
    const char* get_dolgnost()const;
    const char* get_specialnost()const;
    const char* get_truds()const;
    void set_dolgnost(const char* dolgnost);
    void set_specialnost(const char* specialnost);
    void set_truds(const char* truds);

    friend istream &operator>>(istream &in, Prepod &obj);
    friend ostream &operator<<(ostream &out, Prepod &obj);
    Prepod& operator=(const Prepod& other);
    bool operator==(const Prepod &other);

    void printHeader() override;
    void edit() override;
};

#endif
