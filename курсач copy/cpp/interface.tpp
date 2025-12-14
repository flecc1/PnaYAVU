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
        if (typeid(T) == typeid(Book) || typeid(T) == typeid(StandardBook) || typeid(T) == typeid(ResearchPaper)) {
            cout << "14. Работа с рецензиями" << endl;
        }
        cout << "0. Назад" << endl;
        cout << "Выберите действие: ";

        int maxChoice = 13;
        if (typeid(T) == typeid(Book) || typeid(T) == typeid(StandardBook) || typeid(T) == typeid(ResearchPaper)) {
            maxChoice = 14;
        }
        choice = validator.inputNumber(cin, 0, maxChoice);

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
                och.sortByYear();
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
            cout << "Введите параметры для поиска" << endl;
            value.edit();
            Ochered<T> findResult = och.findAllWithParameters(value);
            if (!findResult.is_empty())
            {
                value.printHeader();
                cout << findResult;
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
                    File_txt<T> file(filename);
                    och = file.read();
                    cout << "✓ Загружено " << och.getSize() << " объектов из текстового файла" << endl;
                } catch (const My_exception& e) {
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
                } catch (const My_exception& e) {
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
                    } catch (const My_exception& e) {
                        cout << "✗ Ошибка при открытии файла: ";
                        e.printError();
                    }
                }
            }
            break;
        }
        case 14:  // Работа с рецензиями (только для Book и его наследников)
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
                                    cin >> newReview;
                                    bookPtr->addReview(newReview);
                                    cout << "✓ Рецензия успешно добавлена!" << endl;
                                } catch (const My_exception& e) {
                                    cout << "✗ Ошибка при добавлении рецензии: ";
                                    e.printError();
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
                cout << "Эта функция доступна только для книг!" << endl;
            }
            break;
        }
        case 0:
            break;
        }
    } while (choice != 0);
}

