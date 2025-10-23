#include "headeer.h"

int main()
{
    int repeat;
    do
    {
        menu();
        cout << "\nХотите повторить программу заново? (1 - да, 0 - нет): ";
        cin >> repeat;
    } while (repeat == 1);

    cout << "Программа завершена." << endl;
    return 0;
}
