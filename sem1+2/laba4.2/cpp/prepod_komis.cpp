#include "../headers/prepod_komis.h"

const char* Prepod_Komis::get_spisok_rabot()const
{
    return this->spisok_rabot;
}

void Prepod_Komis::set_spisok_rabot(const char* new_spisok_rabot)
{
    strncpy(this->spisok_rabot, new_spisok_rabot, M - 1);
    this->spisok_rabot[M - 1] = '\0';
}

istream &operator>>(istream &in, Prepod_Komis& obj)
{
    in >> static_cast<Prepod&>(obj);
    cout << "введите имя комисии: ";
    in >> obj.komis_name;
    cout << "введите автобиографию: ";
    in >> obj.autobio;
    cout << "введите что делает член комисии: ";
    in >> obj.spisok_rabot;
    return in;
}

ostream &operator<<(ostream &out, Prepod_Komis& obj)
{
    out << static_cast<Prepod&>(obj);
    out << setw(15) << left << obj.komis_name << setw(20) << left << obj.autobio;
    out << setw(20) << left << obj.spisok_rabot;
    return out;
}

Prepod_Komis& Prepod_Komis::operator=(const Prepod_Komis& other)
{
    if (this != &other)
    {
        Prepod::operator=(other);  // Вызов через одного родителя
        Komisia::operator=(other); // Вызов через другого родителя
        strncpy(this->spisok_rabot, other.spisok_rabot, M - 1);
        this->spisok_rabot[M - 1] = '\0';
    }
    return *this;
}

void Prepod_Komis::printHeader() 
{
    cout << setw(12) << left << "Name" 
        << setw(14) << left << "Second_name" 
        << setw(8) << left << "Age"
        << setw(12) << left << "Dolgnost"
        << setw(15) << left << "Specialnost"
        << setw(15) << left << "Truds"
        << setw(15) << left << "Komisiya"
        << setw(20) << left << "Autobio" 
        << setw(20) << left << "Spisok_rabot" << endl;
}


void Prepod_Komis::edit() {
    int fieldChoice;
    do {
        cout << "\n=== РЕДАКТИРОВАНИЕ PREPOD_KOMIS ===" << endl;
        cout << "Текущий объект:" << endl;
        printHeader();
        cout << *this << endl;
        
        cout << "\nВыберите поле для изменения:" << endl;
        cout << "1. Имя" << endl;
        cout << "2. Фамилия" << endl;
        cout << "3. Возраст" << endl;
        cout << "4. Должность" << endl;
        cout << "5. Специальность" << endl;
        cout << "6. Список трудов" << endl;
        cout << "7. Название комиссии" << endl;
        cout << "8. Автобиография" << endl;
        cout << "9. Список работ" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите поле: ";
        cin >> fieldChoice;
        
        switch(fieldChoice) {
            case 1: {
                char newName[N];
                cout << "Введите новое имя: ";
                cin >> newName;
                set_name(newName);
                cout << "Имя изменено!" << endl;
                break;
            }
            case 2: {
                char newSurname[N];
                cout << "Введите новую фамилию: ";
                cin >> newSurname;
                set_second_name(newSurname);
                cout << "Фамилия изменена!" << endl;
                break;
            }
            case 3: {
                int newAge;
                cout << "Введите новый возраст: ";
                cin >> newAge;
                set_age(newAge);
                cout << "Возраст изменен!" << endl;
                break;
            }
            case 4: {
                char newDolgnost[M];
                cout << "Введите новую должность: ";
                cin >> newDolgnost;
                set_dolgnost(newDolgnost);
                cout << "Должность изменена!" << endl;
                break;
            }
            case 5: {
                char newSpec[M];
                cout << "Введите новую специальность: ";
                cin >> newSpec;
                set_specialnost(newSpec);
                cout << "Специальность изменена!" << endl;
                break;
            }
            case 6: {
                char newTruds[M];
                cout << "Введите новый список трудов: ";
                cin >> newTruds;
                set_truds(newTruds);
                cout << "Список трудов изменен!" << endl;
                break;
            }
            case 7: {
                char newKomis[M];
                cout << "Введите новое название комиссии: ";
                cin >> newKomis;
                set_komis_name(newKomis);
                cout << "Название комиссии изменено!" << endl;
                break;
            }
            case 8: {
                char newBio[M];
                cout << "Введите новую автобиографию: ";
                cin >> newBio;
                set_autobio(newBio);
                cout << "Автобиография изменена!" << endl;
                break;
            }
            case 9: {
                char newRaboty[M];
                cout << "Введите новый список работ: ";
                cin >> newRaboty;
                set_spisok_rabot(newRaboty);
                cout << "Список работ изменен!" << endl;
                break;
            }
            case 0:
                cout << "Выход из редактора..." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (fieldChoice != 0);
}