#include "header.h"

String &String::operator=(const String &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] str;
    size = other.size;
    str = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        str[i] = other.str[i];
    }
    str[size] = '\0';
    return *this;
}




String String::operator+(const String &other)
{
    String result;
    result.size = this->size + other.size;
    result.str = new char[result.size + 1];
    strcpy(result.str, this->str);
    strcat(result.str, other.str);
    return result;
}



String &String::operator+=(const String &other)
{
    String temp = *this + other;
    delete[] this->str;
    size = temp.size;
    str = new char[size + 1];
    strcpy(this->str, temp.str);
    return *this;
}

String String::operator()(int start, int end)
{
    if (start < 0 || start >= size || end < 0 || start + end > size)
    {
        cout << "недопустимые параметры начала и конца строки" << endl;
        return String("");
    }
    if (end >= 80)
    {
        cout << "слишком длинная подстрока" << endl;
        return String("");
    }
    char buffer[80];
    strncpy(buffer, str + start, end);
    buffer[end] = '\0';
    return String(buffer);
}

bool String::operator<(const String &other) const
{
    if (this->str == nullptr || other.str == nullptr)
        return false;
    return strcmp(this->str, other.str) < 0;
}

bool String::operator>(const String &other) const
{
    if (this->str == nullptr || other.str == nullptr)
        return false;
    return strcmp(this->str, other.str) > 0;
}

bool String::operator==(const String &other) const
{
    if (str == nullptr || other.str == nullptr)
        return false;
    return std::strcmp(str, other.str) == 0;
}

istream &operator>>(istream &in, String &str)
{
    char buffer[80];
    in.getline(buffer, 80);
    delete[] str.str;
    str.size = strlen(buffer);
    str.str = new char[str.size + 1];
    strcpy(str.str, buffer);
    return in;
}

ostream &operator<<(ostream &out, const String &str)
{
    if (str.str != nullptr)
    {
        out << str.str;
    }
    return out;
}

char &String::operator[](int ind)
{
    if (ind >= size || ind < 0)
    {
        return o;
    }
    return str[ind];
}
// Префиксный ++
String& String::operator++() 
{
    for (int i = 0; i < size; ++i) {
        ++str[i];
    }
    return *this;
}
//Префиксный --
String& String::operator--()
{
    for(int i = 0; i < size; ++i)
    {
        --str[i];
    }
    return *this;
}

void menu()
{
    String s1, s2;
    bool s1_exists = false, s2_exists = false;

    int choice;
    do
    {
        cout << COLOR_RED << "\n========== МЕНЮ КЛАССА String ==========" << endl;
        cout << COLOR_BLUE << "| 1.  Создать первую строку            |" << endl;
        cout << COLOR_GREEN << "| 2.  Создать вторую строку            |" << endl;
        cout << COLOR_YELLOW << "| 3.  Вывести строки                   |" << endl;
        cout << COLOR_MAGENTA << "| 4.  Оператор присваивания (=)        |" << endl;
        cout << COLOR_CYAN << "| 5.  Конкатенация строк (+)           |" << endl;
        cout << COLOR_RED << "| 6.  Конкатенация с присваиванием (+=)|" << endl;
        cout << COLOR_BLUE << "| 7.  Получение подстроки ()           |" << endl;
        cout << COLOR_GREEN << "| 8.  Сравнение строк (==, <, >)       |" << endl;
        cout << COLOR_YELLOW << "| 9.  Доступ по индексу []             |" << endl;
        cout << COLOR_CYAN << "| 0.  Выход из меню                    |" << endl;
        cout << COLOR_RESET << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Введите первую строку: ";
            rewind(stdin);
            cin >> s1;
            rewind(stdin);
            s1_exists = true;
            cout << COLOR_GREEN << "✓ Строка s1 успешно создана: '" << s1 << "'" << COLOR_RESET << endl;
            break;
        }

        case 2:
        {
            cout << "Введите вторую строку: ";
            rewind(stdin);
            cin >> s2;
            rewind(stdin);
            s2_exists = true;
            cout << COLOR_GREEN << "✓ Строка s2 успешно создана: '" << s2 << "'" << COLOR_RESET << endl;
            break;
        }

        case 3:
        {
            cout << COLOR_YELLOW << "\n--- Текущие строки ---" << COLOR_RESET << endl;
            if (s1_exists)
            {
                cout << "s1: '" << s1 << "'" << endl;
            }
            else
            {
                cout << COLOR_RED << "✗ Первая строка не создана!" << COLOR_RESET << endl;
            }
            if (s2_exists)
            {
                cout << "s2: '" << s2 << "'" << endl;
            }
            else
            {
                cout << COLOR_RED << "✗ Вторая строка не создана!" << COLOR_RESET << endl;
            }
            break;
        }

        case 4:
        {
            if (!s1_exists || !s2_exists)
            {
                cout << COLOR_RED << "✗ Обе строки должны быть созданы!" << COLOR_RESET << endl;
            }
            else
            {
                cout << COLOR_YELLOW << "\n--- Демонстрация оператора присваивания ---" << COLOR_RESET << endl;
                String s3 = s1;
                cout << "String s3 = s1: '" << s3 << "'" << endl;
                s3 = s2;
                cout << "s3 = s2: '" << s3 << "'" << endl;
            }
            break;
        }

        case 5:
        {
            if (!s1_exists || !s2_exists)
            {
                cout << COLOR_RED << "✗ Обе строки должны быть созданы!" << COLOR_RESET << endl;
            }
            else
            {
                cout << COLOR_YELLOW << "\n--- Демонстрация конкатенации ---" << COLOR_RESET << endl;
                cout << "s1: '" << s1 << "'" << endl;
                cout << "s2: '" << s2 << "'" << endl;
                String s3 = s1 + s2;
                cout << "s1 + s2: '" << s3 << "'" << endl;
            }
            break;
        }

        case 6:
        {
            if (!s1_exists || !s2_exists)
            {
                cout << COLOR_RED << "✗ Обе строки должны быть созданы!" << COLOR_RESET << endl;
            }
            else
            {
                cout << COLOR_YELLOW << "\n--- Демонстрация конкатенации с присваиванием ---" << COLOR_RESET << endl;
                cout << "Исходная строка s1: '" << s1 << "'" << endl;
                cout << "Строка s2: '" << s2 << "'" << endl;
                s1 += s2;
                cout << "После s1 += s2: '" << s1 << "'" << endl;
            }
            break;
        }

        case 7:
        {
            if (!s1_exists)
            {
                cout << COLOR_RED << "✗ Первая строка не создана!" << COLOR_RESET << endl;
            }
            else
            {
                cout << COLOR_YELLOW << "\n--- Демонстрация получения подстроки ---" << COLOR_RESET << endl;
                cout << "Исходная строка: '" << s1 << "'" << endl;

                int start, end;
                bool valid_input = false;

                while (!valid_input)
                {
                    cout << "Введите начальный индекс и длину подстроки: ";
                    cin >> start >> end;

                    // Проверка корректности ввода
                    if (start < 0 || start >= s1.getSize() || end < 0 || start + end > s1.getSize())
                    {
                        cout << COLOR_RED << "✗ Ошибка: недопустимые параметры! " << endl;
                        cout << "Длина строки: " << s1.getSize() << COLOR_RESET << endl;
                        cout << "Пожалуйста, введите корректные значения." << endl;
                    }
                    else if (end >= 80)
                    {
                        cout << COLOR_RED << "✗ Ошибка: длина подстроки не может превышать 79 символов!" << COLOR_RESET << endl;
                    }
                    else
                    {
                        valid_input = true;
                        String substr = s1(start, end);
                        cout << COLOR_GREEN << "✓ Подстрока s1(" << start << ", " << end << "): '" << substr << "'" << COLOR_RESET << endl;
                    }
                }
            }
            break;
        }

        case 8:
        {
            if (!s1_exists || !s2_exists)
            {
                cout << COLOR_RED << "✗ Обе строки должны быть созданы!" << COLOR_RESET << endl;
            }
            else
            {
                cout << COLOR_YELLOW << "\n--- Демонстрация сравнения строк ---" << COLOR_RESET << endl;
                cout << "s1: '" << s1 << "'" << endl;
                cout << "s2: '" << s2 << "'" << endl;
                cout << "s1 == s2: " << (s1 == s2 ? "true" : "false") << endl;
                cout << "s1 < s2: " << (s1 < s2 ? "true" : "false") << endl;
                cout << "s1 > s2: " << (s1 > s2 ? "true" : "false") << endl;
            }
            break;
        }

        case 9:
        {
            if (!s1_exists)
            {
                cout << COLOR_RED << "✗ Первая строка не создана!" << COLOR_RESET << endl;
            }
            else
            {
                cout << COLOR_YELLOW << "\n--- Демонстрация доступа по индексу ---" << COLOR_RESET << endl;
                cout << "Исходная строка: '" << s1 << "'" << endl;

                int index;
                cout << "Введите индекс для доступа к символу: ";
                cin >> index;

                if (index >= 0 && index < s1.getSize())
                {
                    cout << "s1[" << index << "] = '" << s1[index] << "'" << endl;

                    char new_char;
                    cout << "Введите новый символ для замены: ";
                    cin >> new_char;
                    s1[index] = new_char;
                    cout << COLOR_GREEN << "✓ После замены: s1 = '" << s1 << "'" << COLOR_RESET << endl;
                }
                else
                {
                    cout << COLOR_RED << "✗ Ошибка: индекс должен быть в диапазоне [0, " << s1.getSize() - 1 << "]" << COLOR_RESET << endl;
                }
            }
            break;
        }
        case 0:
            cout << COLOR_MAGENTA << "Выход из меню." << COLOR_RESET << endl;
            break;

        default:
            cout << COLOR_RED << "✗ Неверный выбор! Пожалуйста, выберите действие от 0 до 10." << COLOR_RESET << endl;
        }

    } while (choice != 0);
}