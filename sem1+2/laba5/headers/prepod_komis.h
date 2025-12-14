#ifndef PREPODKOMIS_H
#define PREPODKOMIS_H
#include"prepod.h"
#include"komis.h"


class Prepod_Komis:public Prepod, public Komisia
{
    char spisok_rabot[M];//что делает комисия 
    public:
    Prepod_Komis():Prepod(), Komisia()
    {
        spisok_rabot[0] = '\0';
    }
    Prepod_Komis(const char* name, const char* sname, int age, 
        const char* dolgnost, const char* specialnost, const char* truds, 
        const char* komis_name, const char* autobio, const char* raboty)
        : Human(name, sname, age), 
        Prepod(name, sname, age, dolgnost, specialnost, truds),
        Komisia(name, sname, age, komis_name, autobio)
    {
        strncpy(this->spisok_rabot, raboty, M);
        this->spisok_rabot[M - 1] = '\0';
    }
    Prepod_Komis(const Prepod_Komis& other) : Human(other), Prepod(other), Komisia(other)  // Виртуальное наследование!
    {
        strncpy(this->spisok_rabot, other.spisok_rabot, M - 1);
        this->spisok_rabot[M - 1] = '\0';
    }
    ~Prepod_Komis()
    {

    }
    public:
    const char* get_spisok_rabot() const;
    void set_spisok_rabot(const char* spisok_rabot);
    friend istream &operator>>(istream& in, Prepod_Komis &obj);
    friend ostream &operator<<(ostream& out, Prepod_Komis &obj);
    Prepod_Komis& operator=(const Prepod_Komis& other);
    bool operator==(const Prepod_Komis& other);
    void printHeader() override;
    void edit() override;

};
#endif