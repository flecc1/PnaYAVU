#include "../headers/interface.h"
#include "../headers/ochered.h"
#include "../headers/human.h"
#include "../headers/student.h"
#include "../headers/komis.h"
#include "../headers/prepod_komis.h"
#include "error.cpp"
#include <list>
#include "algorithms.h"
#include <fstream>
#include <sstream>
// file exception
#include "../headers/file_exception.h"

template<class T>
void Interface<T>::menu()
{
    int choice;
    Exp_vvoda validator;
    
    do
    {
        Interface<Human> humanobj;
        Interface<Student> studentobj;
        Interface<Komisia> komisobj;
        Interface<Prepod> prepodobj;
        Interface<Prepod_Komis> prepod_komisobj;

        cout << "1. Работа с людьми" << endl;
        cout << "2. Работа с студентами" << endl;
        cout << "3. Работа с комиссией" << endl;
        cout << "4. Работа с преподами" << endl;
        cout << "5. Работа с преподавателями членами комиссии" << endl;
        cout << "0. Выход" << std::endl;

        choice = validator.inputNumber(cin, 0, 5);
            
        switch (choice)
        {
            case 0:
                break;
            case 1:
                humanobj.fun();
                break;
            case 2:
                studentobj.fun();
                break;
            case 3:
                komisobj.fun();
                break;
            case 4:
                prepodobj.fun();
                break;
            case 5:
                prepod_komisobj.fun();
                break;
        }
    } while (choice != 0);
}

template<class T>
void Interface<T>::sortByAge()
{
    och.sortByAge();
}

template <class T>
void Interface<T>::editobj(T& object)
{
    object.edit();
}


template <class T>
void Interface<T>::fun()
{
    int choice;
    Exp_vvoda validator;
    std::list<T> stlList; // контейнер STL для пункта меню
    
    do
    {
        cout << endl;
    cout << "1. Добавить объект" << endl;
        cout << "2. Показать все объекты" << endl;
        cout << "3. Редактирование параметров" << endl;
        cout << "4. Удалить объект" << endl;
        cout << "5. Сортировка" << endl;
        cout << "6. Очистить список" << endl;
        cout << "7. Показать размер списка" << endl;
        cout << "8. Поиск" << endl;
        cout << "9. Сохранить в текстовый файл" << endl;
        cout << "10. Сохранить в бинарный файл" << endl;
        cout << "11. Загрузить из текстового файла" << endl;
        cout << "12. Загрузить из бинарного файла" << endl;
    cout << "13. Показать содержимое файла" << endl;
    cout << "14. Работа со std::list" << endl;
    cout << "0. Назад" << endl;
        cout << "Выберите действие: ";

    choice = validator.inputNumber(cin, 0, 14);
        cin.ignore();
        
        switch (choice)
        {
        case 1:
        {
            T obj;
            try {
                cin >> obj;  
                och.pushback(obj);
                cout << "Объект добавлен!" << endl;
            } catch (const My_exception& e) {
                cout << "Ошибка при добавлении: ";
                e.printError();
            }
            break;
        }
        case 2:
        {
            if (och.is_empty()) 
            {
                cout << "Список пуст!" << endl;
            } 
            else 
            {
                cout << "\n=== СПИСОК ОБЪЕКТОВ ===" << endl;
                T temp;
                temp.printHeader();
                cout << och << endl;
            }
            break;
        }
        case 3:
        {
            if (och.is_empty()) 
            {
                cout << "Нет объектов для редактирования!" << endl;
                break;
            }
            
            cout << "\nТекущий список:" << endl;
            T temp;
            temp.printHeader();
            cout << och << endl;
            
            int index;
            cout << "Введите индекс для редактирования (1-" << och.getSize() << "): ";
            index = validator.inputNumber(cin, 1, och.getSize());
            
            try {
                och[index - 1].edit();
                cout << "Объект отредактирован!" << endl;
            } catch (const My_exception& e) {
                cout << "Ошибка при редактировании: ";
                e.printError();
            }
            break;
        }
        case 4:
        {
            if (och.is_empty()) 
            {
                cout << "Список пуст!" << endl;
                break;
            }
            
            cout << "\nТекущий список:" << endl;
            T temp;
            temp.printHeader();
            cout << och << endl;
            
            int index;
            cout << "Введите индекс для удаления (1-" << och.getSize() << "): ";
            index = validator.inputNumber(cin, 1, och.getSize());
            
            if (och.remove_by_index(index - 1)) {
                cout << "Объект удален!" << endl;
            } else {
                cout << "Ошибка при удалении!" << endl;
            }
            break;
        }
        case 5:
        {
            if (och.is_empty()) 
            {
                cout << "Список пуст!" << endl;
            }
            else
            {
                och.sortByAge();
                cout << "Список отсортирован!" << endl;
            }
            break;
        }
        case 6:
        {
            och.free();
            cout << "Список очищен!" << endl;
            break;
        }
        case 7:
        {
            cout << "Размер списка: " << och.getSize() << " элементов" << endl;
            break;
        }
        case 8:
        {
            T value;
            cout << "Enter parametrs" << endl;
            value.edit();
            Ochered<T> findResult = och.findAllWithParameters(value);
            if (!findResult.is_empty())
            {
                findResult[0].printHeader();
                cout << findResult;
            }
            else
                cout << "No elements found" << endl;
            break;
        }
        case 9:  // Сохранить в текстовый файл
        {
            string filename;
            cout << "\n=== СОХРАНЕНИЕ В ТЕКСТОВЫЙ ФАЙЛ ===" << endl;
            cout << "Введите имя файла (например: data.txt): ";
            getline(cin, filename);
            if (!filename.empty()) {
                try {
                    File_txt<T> file(filename);
                    file.write(och);
                    cout << "✓ Данные успешно сохранены в текстовый файл!" << endl;
                } catch (const File_exception& e) {
                    cout << "✗ Ошибка при сохранении в текстовый файл: ";
                    e.printError();
                }
            }
            break;
        }
        case 10:  // Сохранить в бинарный файл
        {
            string filename;
            cout << "\n=== СОХРАНЕНИЕ В БИНАРНЫЙ ФАЙЛ ===" << endl;
            cout << "Введите имя файла (например: data.bin): ";
            getline(cin, filename);
            if (!filename.empty()) {
                try {
                    File_bin<T> file(filename);
                    file.write(och);
                    cout << "✓ Данные успешно сохранены в бинарный файл!" << endl;
                } catch (const File_exception& e) {
                    cout << "✗ Ошибка при сохранении в бинарный файл: ";
                    e.printError();
                }
            }
            break;
        }
        case 11:  // Загрузить из текстового файла
        {
            string filename;
            cout << "\n=== ЗАГРУЗКА ИЗ ТЕКСТОВОГО ФАЙЛА ===" << endl;
            cout << "Внимание: текущие данные будут заменены!" << endl;
            cout << "Введите имя файла (например: data.txt): ";
            getline(cin, filename);
            if (!filename.empty()) {
                try {
                    File_txt<T> file(filename);
                    och = file.read();
                    cout << "✓ Загружено " << och.getSize() << " объектов из текстового файла" << endl;
                } catch (const File_exception& e) {
                    cout << "✗ Ошибка при загрузке из текстового файла: ";
                    e.printError();
                }
            }
            break;
        }
        case 12:  // Загрузить из бинарного файла
        {
            string filename;
            cout << "\n=== ЗАГРУЗКА ИЗ БИНАРНОГО ФАЙЛА ===" << endl;
            cout << "Внимание: текущие данные будут заменены!" << endl;
            cout << "Введите имя файла (например: data.bin): ";
            getline(cin, filename);
            if (!filename.empty()) {
                try {
                    File_bin<T> file(filename);
                    och = file.read();
                    cout << "✓ Загружено " << och.getSize() << " объектов из бинарного файла" << endl;
                } catch (const File_exception& e) {
                    cout << "✗ Ошибка при загрузке из бинарного файла: ";
                    e.printError();
                }
            }
            break;
        }
        case 13:  // Показать содержимое файла
        {
            string filename;
            cout << "\n=== ПРОСМОТР СОДЕРЖИМОГО ФАЙЛА ===" << endl;
            cout << "Введите имя файла: ";
            getline(cin, filename);
                if (!filename.empty()) {
                try {
                    File_txt<T> file(filename);
                    file.display();
                } catch (...) {
                    try {
                        File_bin<T> file(filename);
                        file.display();
                    } catch (const File_exception& e) {
                        cout << "✗ Ошибка при открытии файла: ";
                        e.printError();
                    }
                }
            }
            break;
        }
        case 14: // Работа со std::list
        {
            int sub;
            do {
                cout << "\n--- Работа со std::list ---\n";
                cout << "1. Добавить элемент" << endl;
                cout << "2. Удалить по индексу" << endl;
                cout << "3. Показать все" << endl;
                cout << "4. Найти по параметрам" << endl;
                cout << "5. Сохранить std::list в текстовый файл" << endl;
                cout << "6. Сохранить std::list в бинарный файл" << endl;
                cout << "7. Загрузить std::list из текстового файла" << endl;
                cout << "8. Загрузить std::list из бинарного файла" << endl;
                cout << "0. Назад" << endl;
                cout << "Выбор: ";
                sub = validator.inputNumber(cin, 0, 8);
                cin.ignore();
                switch (sub) {
                    case 1: {
                        T obj;
                        try {
                            cin >> obj;
                            stlList.push_back(obj);
                            cout << "Объект добавлен в std::list!" << endl;
                        } catch (const My_exception& e) {
                            cout << "Ошибка при добавлении: "; e.printError();
                        }
                        break;
                    }
                    case 2: {
                        if (stlList.empty()) { cout << "Пусто\n"; break; }
                        int idx;
                        cout << "Индекс (1.." << stlList.size() << "): ";
                        idx = validator.inputNumber(cin, 1, stlList.size());
                        {
                            auto it = stlList.begin();
                            std::advance(it, idx - 1);
                            stlList.erase(it);
                        }
                        break;
                    }
                    case 3: {
                        if (stlList.empty()) { cout << "Пусто\n"; break; }
                        T tmp;
                        tmp.printHeader();
                        for (auto &v : stlList) {
                            cout << v << endl;
                        }
                        break;
                    }
                    case 4: {
                        T example;
                        cout << "Введите параметры для поиска:\n";
                        example.edit();
                        auto found = findWithAllParameters(stlList.begin(), stlList.end(), example);
                        if (found.is_empty()) {
                            cout << "Не найдено\n";
                        } else {
                            for (auto &v : found) {
                                v.printHeader();
                                cout << v << endl;
                            }
                        }
                        break;
                    }
                    case 5: {
                        
                        cout << "Введите имя текстового файла для сохранения: ";
                        string filename;
                        getline(cin, filename);
                        try {
                            ofstream out(filename);
                            if (!out.is_open()) throw My_exception(200, "Не удалось открыть файл для записи");

                            int count = 0;
                            for (auto it = stlList.begin(); it != stlList.end(); ++it) ++count;
                            int i = 0;
                            for (auto &elem : stlList) {
                                writeToFile(out, elem);
                                if (i < count - 1) out << endl;
                                ++i;
                            }
                            out.close();
                            cout << "std::list сохранен в текстовый файл \"" << filename << "\"" << endl;
                        } catch (const My_exception &e) {
                            cout << "Ошибка при записи файла: "; e.printError();
                        } catch (const exception &e) {
                            cout << "Ошибка при записи файла: " << e.what() << endl;
                        }
                        break;
                    }
                    case 6: {
                        cout << "Введите имя бинарного файла для сохранения: ";
                        string filename;
                        getline(cin, filename);
                        try {
                            ofstream out(filename, ios::binary);
                            if (!out.is_open()) throw My_exception(201, "Не удалось открыть бинарный файл для записи");
                            int size = static_cast<int>(stlList.size());
                            out.write(reinterpret_cast<const char*>(&size), sizeof(size));
                            for (auto &elem : stlList) {
                                out.write(reinterpret_cast<const char*>(&elem), sizeof(elem));
                            }
                            out.close();
                            cout << "std::list сохранен в бинарный файл \"" << filename << "\"" << endl;
                        } catch (const My_exception &e) {
                            cout << "Ошибка при записи бинарного файла: "; e.printError();
                        } catch (const exception &e) {
                            cout << "Ошибка при записи бинарного файла: " << e.what() << endl;
                        }
                        break;
                    }
                    case 7: {
                        cout << "Введите имя текстового файла для загрузки: ";
                        string filename;
                        getline(cin, filename);
                        try {
                            ifstream in(filename);
                            if (!in.is_open()) throw My_exception(202, "Не удалось открыть файл для чтения");

                            string line;
                            int line_num = 0;
                            stlList.clear();
                            while (getline(in, line)) {
                                ++line_num;
                                if (line.empty() || line.find_first_not_of(' ') == string::npos) continue;
                                try {
                                    istringstream iss(line);
                                    T obj;
                                    readFromFile(iss, obj);
                                    if (iss.fail() && !iss.eof()) throw My_exception(203, "Ошибка формата данных");
                                    stlList.push_back(obj);
                                } catch (const My_exception &e) { throw; }
                            }
                            in.close();
                            cout << "std::list загружен из текстового файла \"" << filename << "\"" << endl;
                        } catch (const My_exception &e) {
                            cout << "Ошибка при чтении файла: "; e.printError();
                        } catch (const exception &e) {
                            cout << "Ошибка при чтении файла: " << e.what() << endl;
                        }
                        break;
                    }
                    case 8: {
                        cout << "Введите имя бинарного файла для загрузки: ";
                        string filename;
                        getline(cin, filename);
                        try {
                            ifstream in(filename, ios::binary);
                            if (!in.is_open()) throw My_exception(204, "Не удалось открыть бинарный файл для чтения");
                            int size = 0;
                            in.read(reinterpret_cast<char*>(&size), sizeof(size));
                            if (!in.good()) throw My_exception(205, "Ошибка при чтении размера");
                            stlList.clear();
                            for (int i = 0; i < size; ++i) {
                                T obj;
                                in.read(reinterpret_cast<char*>(&obj), sizeof(obj));
                                if (!in.good() && i < size - 1) throw My_exception(206, "Ошибка при чтении данных");
                                stlList.push_back(obj);
                            }
                            in.close();
                            cout << "std::list загружен из бинарного файла \"" << filename << "\"" << endl;
                        } catch (const My_exception &e) {
                            cout << "Ошибка при чтении бинарного файла: "; e.printError();
                        } catch (const exception &e) {
                            cout << "Ошибка при чтении бинарного файла: " << e.what() << endl;
                        }
                        break;
                    }
                }
            } while (sub != 0);
            break;
        }
        case 0:
            break;
        }
    } while (choice != 0);
}