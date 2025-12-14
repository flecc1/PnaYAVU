#include "../headers/Interface.h"
#include "../headers/Monoblock.h"
#include "../headers/Tablet.h"
#include "../headers/Laptop.h"

template <class T>
void Interface<T>::mainMenu()
{

    int choice;
    do
    {
        std::cout << "========================== Main menu ==========================" << std::endl;
        std::cout << "1. Monoblock menu" << std::endl;
        std::cout << "2. Laptop menu" << std::endl;
        std::cout << "3. Tablet menu" << std::endl;
        std::cout << "0. End " << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        switch (choice)
        {
        case 1:
        {
            Interface<Monoblock> monoblock;
            monoblock.editList();
            break;
        }
        case 2:
        {
            Interface<Laptop> laptops;
            laptops.editList();
            break;
        }
        case 3:
        {
            Interface<Tablet> tablets;
            tablets.editList();
            break;
        }
        case 0:
        {
            break;
        }

        default:
        {
            std::cout << "error choice" << std::endl;
            break;
        }
        }
    } while (choice != 0);
}

template <class T>
void Interface<T>::editList()
{
    LinkedList<T> objects;
    int choice;
    do
    {
        std::cout << "========================== edit list menu ==========================" << std::endl;
        std::cout << "1. add element" << std::endl;
        std::cout << "2. show list" << std::endl;
        std::cout << "3. delete element by index" << std::endl;
        std::cout << "4. delete all" << std::endl;
        std::cout << "5. find by parameters" << std::endl;
        std::cout << "6. change parameters by index" << std::endl;
        std::cout << "0.Return in main menu" << std::endl;
        std::cin >> choice;
        std::cin.ignore();
        switch (choice)
        {
        case 1:
        {
            T value;
            std::cout << "Enter value to add" << std::endl;
            std::cin >> value;
            std::cin.ignore();
            objects.addToBack(value);
            break;
        }
        case 2:
        {
            if (!objects.isEmpty())
            {
                std::cout << "Show list" << std::endl;
                std::cout << objects << std::endl;
            }
            else
                std::cout << "list is empty" << std::endl;
            break;
        }
        case 3:
        {
            int index;
            if (!objects.isEmpty())
            {
                std::cout << "Enter index (from 1 to " << objects.getSize() << ")" << std::endl;
                std::cin >> index;
                index--;
                if (index < 0 || index >= objects.getSize())
                {
                    std::cout << "index error" << std::endl;
                    break;
                }
                objects.remove(index);
            }
            else
                std::cout << "list is empty" << std::endl;
            break;
        }
        case 4:
        {
            objects.clear();
            break;
        }
        case 5:
        {
            T value;
            std::cout << "Enter parametrs" << std::endl;
            value.editParametersMenu();
            LinkedList<T> findResult = objects.findAllWithParameters(value);
            if (!findResult.isEmpty())
            {
                findResult[0].printHead();
                std::cout << findResult;
            }
            else
                std::cout << "No elements found" << std::endl;
            break;
        }
        case 6:
        {
            int index;
            if (!objects.isEmpty())
            {
                std::cout << "Enter index (from 1 to " << objects.getSize() << ")" << std::endl;
                std::cin >> index;
                index--;
                if (index < 0 || index >= objects.getSize())
                {
                    std::cout << "index error" << std::endl;
                    break;
                }
                T &value = objects[index];
                value.editParametersMenu();
            }
            else
                std::cout << "list is empty" << std::endl;
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            std::cout << "error choice" << std::endl;
            break;
        }
        }

    } while (choice != 0);
}
template <class T>
void Interface<T>::editComputingMachine(T &device)
{
    device.editParameterMenu();
}