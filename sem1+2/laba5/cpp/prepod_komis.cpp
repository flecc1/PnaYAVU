#include "../headers/prepod_komis.h"
#include "error.cpp"

const char* Prepod_Komis::get_spisok_rabot()const
{
    return this->spisok_rabot;
}

void Prepod_Komis::set_spisok_rabot(const char* new_spisok_rabot)
{
    if (strlen(new_spisok_rabot) == 0) 
    {
        throw Exp_vvoda(23, "EMPTY_INPUT", "Список работ не может быть пустым");
    }
    strncpy(this->spisok_rabot, new_spisok_rabot, M - 1);
    this->spisok_rabot[M - 1] = '\0';
}

istream &operator>>(istream &in, Prepod_Komis& obj)
{
    // Сначала вводим базовые данные Prepod
    in >> static_cast<Prepod&>(obj);
    
    // Ввод названия комиссии с повторением при ошибке
    while (true) {
        try {
            clearInputBuffer();
            cout << "Введите имя комиссии: ";
            string komis = readString("");
            obj.set_komis_name(komis.c_str());
            break;
        } catch (Exp_vvoda& e) {
            cout << "Ошибка при вводе названия комиссии: ";
            e.printError();
            cout << "Повторите ввод." << endl;
        }
    }
    
    // Ввод автобиографии с повторением при ошибке
    while (true) {
        try {
            cout << "Введите автобиографию: ";
            string bio = readString("");
            obj.set_autobio(bio.c_str());
            break;
        } catch (Exp_vvoda& e) {
            cout << "Ошибка при вводе автобиографии: ";
            e.printError();
            cout << "Повторите ввод." << endl;
        }
    }
    
    // Ввод списка работ с повторением при ошибке
    while (true) {
        try {
            cout << "Введите что делает член комиссии: ";
            string raboty = readString("");
            obj.set_spisok_rabot(raboty.c_str());
            break;
        } catch (Exp_vvoda& e) {
            cout << "Ошибка при вводе списка работ: ";
            e.printError();
            cout << "Повторите ввод." << endl;
        }
    }
    
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
        Prepod::operator=(other);
        Komisia::operator=(other);
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
        
        try {
            fieldChoice = inputNumber(0, 9);
            
            switch(fieldChoice) {
                case 1: {
                    clearInputBuffer();
                    string newName = readName();
                    set_name(newName.c_str());
                    cout << "Имя изменено!" << endl;
                    break;
                }
                case 2: {
                    clearInputBuffer();
                    string newSurname = readSurname();
                    set_second_name(newSurname.c_str());
                    cout << "Фамилия изменена!" << endl;
                    break;
                }
                case 3: {
                    int newAge = inputNumber(0, 100);
                    set_age(newAge);
                    cout << "Возраст изменен!" << endl;
                    break;
                }
                case 4: {
                    clearInputBuffer();
                    string newDolg = readString("Новая должность: ");
                    set_dolgnost(newDolg.c_str());
                    cout << "Должность изменена!" << endl;
                    break;
                }
                case 5: {
                    clearInputBuffer();
                    string newSpec = readString("Новая специальность: ");
                    set_specialnost(newSpec.c_str());
                    cout << "Специальность изменена!" << endl;
                    break;
                }
                case 6: {
                    clearInputBuffer();
                    string newTruds = readString("Новый список трудов: ");
                    set_truds(newTruds.c_str());
                    cout << "Список трудов изменен!" << endl;
                    break;
                }
                case 7: {
                    clearInputBuffer();
                    string newKomis = readString("Новое название комиссии: ");
                    set_komis_name(newKomis.c_str());
                    cout << "Название комиссии изменено!" << endl;
                    break;
                }
                case 8: {
                    clearInputBuffer();
                    string newBio = readString("Новая автобиография: ");
                    set_autobio(newBio.c_str());
                    cout << "Автобиография изменена!" << endl;
                    break;
                }
                case 9: {
                    clearInputBuffer();
                    string newRaboty = readString("Новый список работ: ");
                    set_spisok_rabot(newRaboty.c_str());
                    cout << "Список работ изменен!" << endl;
                    break;
                }
                case 0:
                    cout << "Выход из редактора..." << endl;
                    break;
            }
        } catch (Exp_vvoda& e) {
            cout << "Ошибка при вводе: ";
            e.printError();
            fieldChoice = -1;
        }
    } while (fieldChoice != 0);
}