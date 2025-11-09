#ifndef KOMIS_H
#define KOMIS_H
#define M 80
#include"human.h"
class Komisia:virtual public Human
{
    protected:
    char komis_name[M];
    char autobio[M];
    public:
    Komisia():Human()
    {
        strcpy(komis_name, "");
        strcpy(autobio, "");
    }
    Komisia(const char* name, const char* sname, int age, const char* komis_name, const char* autobio):Human(name, sname, age)
    {
        strncpy(this->komis_name, komis_name, M);
        strncpy(this->autobio, autobio, M);
        this->komis_name[M - 1] = '\0';
        this->autobio[M - 1] = '\0';
    }
    Komisia(const Komisia& other) : Human(other)
    {
        strncpy(this->komis_name, other.komis_name, M);
        strncpy(this->autobio, other.autobio, M);
        this->komis_name[M - 1] = '\0';
        this->autobio[M - 1] = '\0';
    }
    ~Komisia()
    {

    }
    public:
    const char* get_komis_name()const;
    const char* get_autobio()const;
    void set_komis_name(const char* kname);
    void set_autobio(const char* bio);
    friend istream &operator>>(istream &in, Komisia &obj);
    friend ostream &operator<<(ostream &out, Komisia &obj);
    Komisia& operator=(const Komisia& other);

    void printHeader() override;
};
#endif
