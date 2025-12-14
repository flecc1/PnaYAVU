#include "../headers/interface.h"
#include "../headers/ochered.h"
#include "../headers/LibraryItem.h"
#include "../headers/Book.h"
#include "../headers/AudioMaterial.h"
#include "../headers/AudioBook.h"
#include "../headers/StandardBook.h"
#include "../headers/EducationalAudio.h"
#include "../headers/ResearchPaper.h"
#include "../headers/Review.h"
#include <typeinfo>
#include <iomanip>
#include <map>
#include <algorithm>

template<class T>
void Interface<T>::menu()
{
    int choice;
    Exp_vvoda validator;
    
    do
    {
        Interface<LibraryItem> libraryItemObj;
        Interface<Book> bookObj;
        Interface<AudioMaterial> audioMaterialObj;
        Interface<AudioBook> audioBookObj;
        Interface<StandardBook> standardBookObj;
        Interface<EducationalAudio> educationalAudioObj;
        Interface<ResearchPaper> researchPaperObj;

        cout << "1. Работа с элементами библиотеки" << endl;
        cout << "2. Работа с книгами" << endl;
        cout << "3. Работа с аудиоматериалами" << endl;
        cout << "4. Работа с аудиокнигами" << endl;
        cout << "5. Работа со стандартными книгами" << endl;
        cout << "6. Работа с образовательными аудио" << endl;
        cout << "7. Работа с научными статьями" << endl;
        cout << "0. Выход" << std::endl;

        choice = validator.inputNumber(cin, 0, 7);
            
        switch (choice)
        {
            case 0:
                break;
            case 1:
                libraryItemObj.fun();
                break;
            case 2:
                bookObj.fun();
                break;
            case 3:
                audioMaterialObj.fun();
                break;
            case 4:
                audioBookObj.fun();
                break;
            case 5:
                standardBookObj.fun();
                break;
            case 6:
                educationalAudioObj.fun();
                break;
            case 7:
                researchPaperObj.fun();
                break;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
        }
    } while (choice != 0);
}

template<class T>
void Interface<T>::sortByYear()
{
    och.sortByYear();
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
        cout << "14. Статистика и отчеты библиотеки" << endl;
        if (typeid(T) == typeid(Book) || typeid(T) == typeid(StandardBook) || typeid(T) == typeid(ResearchPaper)) {
            cout << "15. Работа с рецензиями" << endl;
            cout << "16. Отменить последнее действие" << endl;
        } else {
            cout << "15. Отменить последнее действие" << endl;
        }
        cout << "0. Назад" << endl;
        cout << "Выберите действие: ";

        int maxChoice = 15;
        if (typeid(T) == typeid(Book) || typeid(T) == typeid(StandardBook) || typeid(T) == typeid(ResearchPaper)) {
            maxChoice = 16;
        }
        choice = validator.inputNumber(cin, 0, maxChoice);

        switch (choice)
        {
        case 1:
        {
            T obj;
            try {
                saveState();  // Сохраняем состояние перед добавлением
                cin >> obj;  
                och.pushback(obj);
                cout << "Объект добавлен!" << endl;
            } catch (const My_exception& e) {
                cout << "Ошибка при добавлении: ";
                e.printError();
                // Если ошибка, убираем последнее сохраненное состояние
                if (!undoStack.empty()) {
                    undoStack.pop();
                }
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
                saveState();  // Сохраняем состояние перед редактированием
                och[index - 1].edit();
                cout << "Объект отредактирован!" << endl;
            } catch (const My_exception& e) {
                cout << "Ошибка при редактировании: ";
                e.printError();
                // Если ошибка, убираем последнее сохраненное состояние
                if (!undoStack.empty()) {
                    undoStack.pop();
                }
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
            
            saveState();  // Сохраняем состояние перед удалением
            if (och.remove_by_index(index - 1)) {
                cout << "Объект удален!" << endl;
            } else {
                cout << "Ошибка при удалении!" << endl;
                // Если ошибка, убираем последнее сохраненное состояние
                if (!undoStack.empty()) {
                    undoStack.pop();
                }
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
                saveState();  // Сохраняем состояние перед сортировкой
                och.sortByYear();
                cout << "Список отсортирован!" << endl;
            }
            break;
        }
        case 6:
        {
            if (!och.is_empty()) {
                saveState();  // Сохраняем состояние перед очисткой
                och.free();
                cout << "Список очищен!" << endl;
            } else {
                cout << "Список уже пуст!" << endl;
            }
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
            cout << "Введите параметры для поиска" << endl;
            value.edit();
            Ochered<T> findResult = och.findAllWithParameters(value);
            if (!findResult.is_empty())
            {
                cout << "\n=== РЕЗУЛЬТАТЫ ПОИСКА ===" << endl;
                value.printHeader();
                cout << findResult << endl;
                
                // Предлагаем сохранить результаты
                cout << "\nСохранить результаты поиска?" << endl;
                cout << "1. Сохранить в текстовый файл" << endl;
                cout << "2. Сохранить в бинарный файл" << endl;
                cout << "0. Не сохранять" << endl;
                cout << "Ваш выбор: ";
                
                int saveChoice = validator.inputNumber(cin, 0, 2);
                cin.ignore();
                
                if (saveChoice == 1) {
                    string filename;
                    cout << "\nВведите имя файла (например: search_result.txt): ";
                    getline(cin, filename);
                    if (!filename.empty()) {
                        try {
                            File_txt<T> file(filename);
                            file.write(findResult);
                            cout << "✓ Результаты поиска сохранены в текстовый файл!" << endl;
                        } catch (const My_exception& e) {
                            cout << "✗ Ошибка при сохранении: ";
                            e.printError();
                        }
                    }
                } else if (saveChoice == 2) {
                    string filename;
                    cout << "\nВведите имя файла (например: search_result.bin): ";
                    getline(cin, filename);
                    if (!filename.empty()) {
                        try {
                            File_bin<T> file(filename);
                            file.write(findResult);
                            cout << "✓ Результаты поиска сохранены в бинарный файл!" << endl;
                        } catch (const My_exception& e) {
                            cout << "✗ Ошибка при сохранении: ";
                            e.printError();
                        }
                    }
                }
            }
            else
                cout << "Элементы не найдены" << endl;
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
                } catch (const My_exception& e) {
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
                } catch (const My_exception& e) {
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
                    saveState();  // Сохраняем состояние перед загрузкой
                    File_txt<T> file(filename);
                    och = file.read();
                    cout << "✓ Загружено " << och.getSize() << " объектов из текстового файла" << endl;
                } catch (const My_exception& e) {
                    cout << "✗ Ошибка при загрузке из текстового файла: ";
                    e.printError();
                    // Если ошибка, убираем последнее сохраненное состояние
                    if (!undoStack.empty()) {
                        undoStack.pop();
                    }
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
                    saveState();  // Сохраняем состояние перед загрузкой
                    File_bin<T> file(filename);
                    och = file.read();
                    cout << "✓ Загружено " << och.getSize() << " объектов из бинарного файла" << endl;
                } catch (const My_exception& e) {
                    cout << "✗ Ошибка при загрузке из бинарного файла: ";
                    e.printError();
                    // Если ошибка, убираем последнее сохраненное состояние
                    if (!undoStack.empty()) {
                        undoStack.pop();
                    }
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
                    } catch (const My_exception& e) {
                        cout << "✗ Ошибка при открытии файла: ";
                        e.printError();
                    }
                }
            }
            break;
        }
        case 14:  // Статистика и отчеты библиотеки
        {
            showStatistics();
            break;
        }
        case 15:  // Работа с рецензиями (только для Book и его наследников)
        {
            if (typeid(T) == typeid(Book) || typeid(T) == typeid(StandardBook) || typeid(T) == typeid(ResearchPaper)) {
                if (och.is_empty()) {
                    cout << "Список книг пуст!" << endl;
                    break;
                }
                
                cout << "\nТекущий список книг:" << endl;
                T temp;
                temp.printHeader();
                cout << och << endl;
                
                int bookIndex;
                cout << "Введите индекс книги для работы с рецензиями (1-" << och.getSize() << "): ";
                bookIndex = validator.inputNumber(cin, 1, och.getSize());
                
                Book* bookPtr = dynamic_cast<Book*>(&och[bookIndex - 1]);
                if (bookPtr) {
                    int reviewChoice;
                    do {
                        cout << "\n=== РАБОТА С РЕЦЕНЗИЯМИ ===" << endl;
                        cout << "Книга: " << bookPtr->getTitle() << endl;
                        cout << "Количество рецензий: " << bookPtr->getReviewCount() << endl;
                        if (bookPtr->getReviewCount() > 0) {
                            cout << "Средняя оценка: " << fixed << setprecision(2) << bookPtr->getAverageRating() << endl;
                        }
                        cout << "\n1. Добавить рецензию" << endl;
                        cout << "2. Просмотреть все рецензии" << endl;
                        cout << "3. Удалить рецензию" << endl;
                        cout << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        
                        reviewChoice = validator.inputNumber(cin, 0, 3);
                        
                        switch(reviewChoice) {
                            case 1: {
                                Review newReview;
                                try {
                                    saveState();  // Сохраняем состояние перед добавлением рецензии
                                    cin >> newReview;
                                    bookPtr->addReview(newReview);
                                    cout << "✓ Рецензия успешно добавлена!" << endl;
                                } catch (const My_exception& e) {
                                    cout << "✗ Ошибка при добавлении рецензии: ";
                                    e.printError();
                                    // Если ошибка, убираем последнее сохраненное состояние
                                    if (!undoStack.empty()) {
                                        undoStack.pop();
                                    }
                                }
                                break;
                            }
                            case 2: {
                                bookPtr->displayAllReviews();
                                break;
                            }
                            case 3: {
                                if (bookPtr->getReviewCount() == 0) {
                                    cout << "Нет рецензий для удаления!" << endl;
                                    break;
                                }
                                bookPtr->displayAllReviews();
                                int reviewIndex;
                                cout << "Введите номер рецензии для удаления (1-" << bookPtr->getReviewCount() << "): ";
                                reviewIndex = validator.inputNumber(cin, 1, bookPtr->getReviewCount());
                                saveState();  // Сохраняем состояние перед удалением рецензии
                                bookPtr->removeReview(reviewIndex - 1);
                                cout << "✓ Рецензия удалена!" << endl;
                                break;
                            }
                            case 0:
                                break;
                        }
                    } while (reviewChoice != 0);
                } else {
                    cout << "Ошибка: невозможно работать с рецензиями для этого типа объекта" << endl;
                }
            } else {
                // Для обычных типов - отмена действия
                undo();
            }
            break;
        }
        case 16:  // Отменить последнее действие (только для Book и его наследников)
        {
            undo();
            break;
        }
        case 0:
            break;
        default:
            cout << "Неверный выбор!" << endl;
            break;
        }
    } while (choice != 0);
}

template<class T>
void Interface<T>::saveState()
{
    // Сохраняем копию текущего состояния в стек
    Ochered<T> stateCopy;
    for (int i = 0; i < och.getSize(); i++) {
        stateCopy.pushback(och[i]);
    }
    undoStack.push(stateCopy);
}

template<class T>
void Interface<T>::undo()
{
    if (undoStack.empty()) {
        cout << "Нет действий для отмены!" << endl;
        return;
    }
    
    // Восстанавливаем предыдущее состояние
    och = undoStack.top();
    undoStack.pop();
    cout << "✓ Последнее действие отменено!" << endl;
}

template<class T>
void Interface<T>::showStatistics()
{
    if (och.is_empty()) {
        cout << "\n=== СТАТИСТИКА БИБЛИОТЕКИ ===" << endl;
        cout << "Библиотека пуста!" << endl;
        return;
    }
    
    cout << "\n=== СТАТИСТИКА И ОТЧЕТЫ БИБЛИОТЕКИ ===" << endl;
    
    // Общая статистика
    int totalItems = och.getSize();
    int totalCopies = 0;
    double totalValue = 0.0;
    double avgPrice = 0.0;
    int oldestYear = 9999;
    int newestYear = 0;
    
    // Подсчет статистики
    for (int i = 0; i < och.getSize(); i++) {
        LibraryItem* item = dynamic_cast<LibraryItem*>(&och[i]);
        if (item) {
            totalCopies += item->getAvailableCopies();
            totalValue += item->getPrice() * item->getAvailableCopies();
            if (item->getYear() > 0) {
                if (item->getYear() < oldestYear) oldestYear = item->getYear();
                if (item->getYear() > newestYear) newestYear = item->getYear();
            }
        }
    }
    
    if (totalCopies > 0) {
        avgPrice = totalValue / totalCopies;
    }
    
    // Вывод общей статистики в виде таблицы
    cout << "\n--- ОБЩАЯ СТАТИСТИКА ---" << endl;
    cout << setw(30) << left << "Pokazatel" << setw(20) << left << "Znachenie" << endl;
    cout << string(50, '-') << endl;
    cout << setw(30) << left << "Obschee kolichestvo elementov" << setw(20) << left << totalItems << endl;
    cout << setw(30) << left << "Obschee kolichestvo kopiy" << setw(20) << left << totalCopies << endl;
    cout << setw(30) << left << "Obschaya stoimost" << setw(20) << left << fixed << setprecision(2) << totalValue << endl;
    if (totalCopies > 0) {
        cout << setw(30) << left << "Srednyaya cena" << setw(20) << left << fixed << setprecision(2) << avgPrice << endl;
    }
    if (oldestYear != 9999) {
        cout << setw(30) << left << "Samyi staryi god" << setw(20) << left << oldestYear << endl;
        cout << setw(30) << left << "Samyi novyi god" << setw(20) << left << newestYear << endl;
    }
    
    // Статистика по жанрам
    map<string, int> genreCount;
    map<string, int> genreCopies;
    
    for (int i = 0; i < och.getSize(); i++) {
        LibraryItem* item = dynamic_cast<LibraryItem*>(&och[i]);
        if (item && !item->getGenre().empty()) {
            genreCount[item->getGenre()]++;
            genreCopies[item->getGenre()] += item->getAvailableCopies();
        }
    }
    
    if (!genreCount.empty()) {
        cout << "\n--- СТАТИСТИКА ПО ЖАНРАМ ---" << endl;
        cout << setw(20) << left << "Zhanr"
             << setw(15) << left << "Kolichestvo"
             << setw(15) << left << "Kopii" << endl;
        cout << string(50, '-') << endl;
        
        for (const auto& pair : genreCount) {
            cout << setw(20) << left << pair.first
                 << setw(15) << left << pair.second
                 << setw(15) << left << genreCopies[pair.first] << endl;
        }
    }
    
    // Вывод всех элементов в виде таблицы
    cout << "\n--- ВСЕ ЭЛЕМЕНТЫ БИБЛИОТЕКИ ---" << endl;
    T temp;
    temp.printHeader();
    cout << och << endl;
}

