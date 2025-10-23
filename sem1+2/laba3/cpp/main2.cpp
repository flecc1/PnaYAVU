#include "../headers/human.h"
#include "../headers/prepod.h"
#include "../headers/komis.h"
#include "../headers/student.h"
#include "../headers/prepod_komis.h"

int main()
{
    int size;
    
    //массив объектов Human
    cout << "=== КЛАСС Human ===" << endl;
    cout << "Введите размер массива: ";
    cin >> size;
    rewind(stdin);
    
    Human* humans = new Human[size];
    
    cout << "\n--- Ввод данных ---" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Человек " << i + 1 << ":" << endl;
        cin >> humans[i];
        rewind(stdin);
    }
    
    cout << "\n--- Таблица Human ---" << endl;
    humans[0].printHeader();
    for(int i = 0; i < size; i++)
    {
        cout << humans[i];
        cout << endl;
    }
    
    //массив объектов Prepod
    cout << "\n\n=== КЛАСС Prepod ===" << endl;
    cout << "Введите размер массива: ";
    cin >> size;
    rewind(stdin);
    
    Prepod* prepods = new Prepod[size];
    
    cout << "\n--- Ввод данных ---" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Преподаватель " << i + 1 << ":" << endl;
        cin >> prepods[i];
        rewind(stdin);
    }
    
    cout << "\n--- Таблица Prepod ---" << endl;
    prepods[0].printHeader();
    for(int i = 0; i < size; i++)
    {
        cout << prepods[i];
        cout << endl;
    }
    
    //массив объектов Komisia
    cout << "\n\n=== КЛАСС Komisia ===" << endl;
    cout << "Введите размер массива: ";
    cin >> size;
    rewind(stdin);
    
    Komisia* komisias = new Komisia[size];
    
    cout << "\n--- Ввод данных ---" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Член комиссии " << i + 1 << ":" << endl;
        cin >> komisias[i];
        rewind(stdin);
    }
    
    cout << "\n--- Таблица Komisia ---" << endl;
    komisias[0].printHeader();
    for(int i = 0; i < size; i++)
    {
        cout << komisias[i];
        cout << endl;
    }
    

    //массив объектов Student
    cout << "\n\n=== КЛАСС Student ===" << endl;
    cout << "Введите размер массива: ";
    cin >> size;
    rewind(stdin);

    Student* students = new Student[size];
    
    cout << "\n--- Ввод данных ---" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Студент " << i + 1 << ":" << endl;
        cin >> students[i];
        rewind(stdin);
    }
    
    cout << "\n--- Таблица Students ---" << endl;
    students[0].printHeader();
    for(int i = 0; i < size; i++)
    {
        cout << students[i];
        cout << endl;
    }


    //массив объектов Prepod_Komis
    cout << "\n\n=== КЛАСС Prepod_Komis ===" << endl;
    cout << "Введите размер массива: ";
    cin >> size;
    rewind(stdin);
    
    Prepod_Komis* prepodKomis = new Prepod_Komis[size];
    
    cout << "\n--- Ввод данных ---" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "Преподаватель-член комиссии " << i + 1 << ":" << endl;
        cin >> prepodKomis[i];
        rewind(stdin);
    }
    
    cout << "\n--- Таблица Prepod_Komis ---" << endl;
    prepodKomis[0].printHeader();
    for(int i = 0; i < size; i++)
    {
        cout << prepodKomis[i];
        cout << endl;
    }

    // Демонстрация работы с объектом Student
    cout << "\n=== Демонстрация работы с объектом Student ===" << endl;
    Student stud("EGOR", "LESK", 18, 8.2, 200);
    cout << "средний бал егора: " << stud.get_sr_bal() << endl;
    cout << "степендия егора: " << stud.get_stependiya() << endl;

    cout << "введите новый средний бал: ";
    double a;
    cin >> a;
    stud.set_sr_bal(a);

    cout << "введите новую стипендию: ";
    int b;
    cin >> b;
    stud.set_stependiya(b);

    cout << "новый средний бал егора: " << stud.get_sr_bal() << endl;
    cout << "новая степендия егора: " << stud.get_stependiya() << endl;

    // Очистка памяти
    delete[] humans;
    delete[] prepods;
    delete[] komisias;
    delete[] students;
    delete[] prepodKomis;
    
    return 0;
}