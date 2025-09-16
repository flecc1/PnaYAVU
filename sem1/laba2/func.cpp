#include "headeer.h"

Mas Mas::merge(const Mas &obj)
{
    Mas temp(size + obj.size);
    int count = 0;

    // добавляем уникальные из первого массива
    for (int i = 0; i < size; i++)
    {
        bool exists = false;
        for (int j = 0; j < count; j++)
        {
            if (temp.arr[j] == arr[i])
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            temp.arr[count++] = arr[i];
        }
    }

    // добавляем уникальные из второго массива которых нет в temp
    for (int i = 0; i < obj.size; i++)
    {
        bool exists = false;
        for (int j = 0; j < count; j++)
        {
            if (temp.arr[j] == obj.arr[i])
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            temp.arr[count++] = obj.arr[i];
        }
    }

    Mas result(count);
    for (int i = 0; i < count; i++)
    {
        result.arr[i] = temp.arr[i];
    }
    return result;
}

void Mas::sort()
{
    if (arr == nullptr || size == 0)
    {
        cout << "массив пуст" << endl;
        return;
    }
    // бубле сорт)
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    cout << "массив отсортирован" << endl;
}

istream &operator>>(istream &in, Mas &arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        cout << "введите " << i + 1 << "элемент: ";
        in >> arr.arr[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const Mas &arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        out << setw(5) << arr.arr[i];
    }
    return out;
}

void menu()
{
    Mas m1, m2;
    int size1 = 0, size2 = 0;
    bool m1_ex, m2_ex;

    int choice;
    do
    {
        cout << COLOR_RED << "\n========== МЕНЮ ==========" << endl;
        cout << COLOR_BLUE << "|1. Ввести первый массив |" << endl;
        cout << COLOR_GREEN << "|2. Ввести второй массив |" << endl;
        cout << COLOR_YELLOW << "|3. Вывести первый массив|" << endl;
        cout << COLOR_MAGENTA << "|4. Вывести второй массив|" << endl;
        cout << COLOR_RED << "|5. Объединить массивы.  |" << endl;
        cout << "|6. Сортировать массив.  |" << endl;
        cout << COLOR_BLUE << "|0. Выход.               |" << endl;
        cout << COLOR_RESET "Выберите действие: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Введите размер первого массива: ";
            cin >> size1;
            m1 = Mas(size1);
            cin >> m1;
            m1_ex = true;
            break;

        case 2:
            cout << "Введите размер второго массива: ";
            cin >> size2;
            m2 = Mas(size2);
            cin >> m2;
            m2_ex = true;
            break;

        case 3:
            cout << "Первый массив: ";
            cout << m1;
            break;

        case 4:
            cout << "Второй массив: ";
            cout << m1;
            break;

        case 5:
            if (!m1_ex == true || !m2_ex == true)
            {
                cout << "Оба массива должны быть введены!" << endl;
            }
            else
            {
                Mas merged = m1.merge(m2); // создаём новый объект
                cout << "Результат объединения: ";
                cout << merged;
                cout << endl;
            }
            break;

        case 6:
            int sortChoice;
            cout << "Какой массив отсортировать? (1 - первый, 2 - второй): ";
            cin >> sortChoice;
            if (sortChoice == 1)
                m1.sort();
            else if (sortChoice == 2)
                m2.sort();
            else
                cout << "Неверный выбор!" << endl;
            break;

        case 0:
            cout << "Выход из программы" << endl;
            break;

        default:
            cout << "Неверный выбор" << endl;
        }

    } while (choice != 0);
}

Mas Mas::operator=(const Mas &other)
{
    if (this == &other)
        return *this;

    delete[] arr;
    size = other.size;
    arr = new int[other.size];
    for (int i = 0; i < other.size; i++)
        arr[i] = other.arr[i];
    return *this;
}

/*2 лаба добавить перегрузку в первую лабубу)))))
+
разоаботать класс string для работы со строками в классе перегрузить
след операции +, +=, =, ==, <, >, [],{ ()(int, int) - выделить подстроку}
должен быть конструктор
с параметром, без параметров, по умолчанию, копирования
реализовать friend функцию или перегрузку операции ввода вывода в поток
*/