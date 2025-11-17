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
    
    // Создаем объект исключения для использования методов
    Exp_vvoda validator;
    
    // Ввод названия комиссии - цикл внутри метода исключения
    string komis = validator.inputString("Введите имя комиссии: ", in);
    obj.set_komis_name(komis.c_str());
    
    // Ввод автобиографии - цикл внутри метода исключения
    string bio = validator.inputString("Введите автобиографию: ", in);
    obj.set_autobio(bio.c_str());
    
    // Ввод списка работ - цикл внутри метода исключения
    string raboty = validator.inputString("Введите что делает член комиссии: ", in);
    obj.set_spisok_rabot(raboty.c_str());
    
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
    // Создаем объекты исключений для использования методов
    Exp_vvoda validator;
    My_exception numValidator;
    
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
        
        fieldChoice = numValidator.inputNumber(0, 9);
        
        switch(fieldChoice) {
            case 1: {
                cout << "Введите новое имя: ";
                string newName = validator.inputName();
                set_name(newName.c_str());
                cout << "Имя изменено!" << endl;
                break;
            }
            case 2: {
                cout << "Введите новую фамилию: ";
                string newSurname = validator.inputSurname();
                set_second_name(newSurname.c_str());
                cout << "Фамилия изменена!" << endl;
                break;
            }
            case 3: {
                cout << "Введите новый возраст: ";
                int newAge = numValidator.inputNumber(0, 100);
                set_age(newAge);
                cout << "Возраст изменен!" << endl;
                break;
            }
            case 4: {
                string newDolg = validator.inputString("Новая должность: ");
                set_dolgnost(newDolg.c_str());
                cout << "Должность изменена!" << endl;
                break;
            }
            case 5: {
                string newSpec = validator.inputString("Новая специальность: ");
                set_specialnost(newSpec.c_str());
                cout << "Специальность изменена!" << endl;
                break;
            }
            case 6: {
                string newTruds = validator.inputString("Новый список трудов: ");
                set_truds(newTruds.c_str());
                cout << "Список трудов изменен!" << endl;
                break;
            }
            case 7: {
                string newKomis = validator.inputString("Новое название комиссии: ");
                set_komis_name(newKomis.c_str());
                cout << "Название комиссии изменено!" << endl;
                break;
            }
            case 8: {
                string newBio = validator.inputString("Новая автобиография: ");
                set_autobio(newBio.c_str());
                cout << "Автобиография изменена!" << endl;
                break;
            }
            case 9: {
                string newRaboty = validator.inputString("Новый список работ: ");
                set_spisok_rabot(newRaboty.c_str());
                cout << "Список работ изменен!" << endl;
                break;
            }
            case 0:
                cout << "Выход из редактора..." << endl;
                break;
        }
    } while (fieldChoice != 0);
}