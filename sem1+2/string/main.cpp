#include"header.h"
/*
int main() 
{
    int restart;
    do {
        menu();
        cout << COLOR_GREEN << "\nНачать заново? (1 - да, все остальное - нет): " << COLOR_RESET;
        cin >> restart;
    } while(restart == 1);

    cout << COLOR_MAGENTA << "Программа завершена." << COLOR_RESET << endl;
    return 0;
}
*/

int main()
{
    String a;
    cin>>a;
    cout<<a<<endl;
    a.operator++();
    cout<< a<< endl;

    a.operator--();
    cout<< a<< endl;
    String b;
    cin>>b;
    String c;
    cin>> c;
    String d;
    cin>>d;
    cout << ((++(a += b)(1, 3) + --c) == d ? a : b)[2] << endl;
    cout<<a + b;
    return 0;
}