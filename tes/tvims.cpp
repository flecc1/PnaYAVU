#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел
    const int totalGames = 12123; // Количество симуляций
    int stayWins = 0; // Победы без смены двери
    int switchWins = 0; // Победы со сменой двери

    for (int i = 0; i < totalGames; i++) {
        // Приз находится за случайной дверью
        int prizeDoor = rand() % 3;
        
        // Игрок выбирает случайную дверь
        int playerChoice = rand() % 3;
        
        // Ведущий открывает дверь с козой
        int hostOpen;
        do {
            hostOpen = rand() % 3;
        } while (hostOpen == prizeDoor || hostOpen == playerChoice);
        
        // Игрок меняет выбор на оставшуюся дверь
        int switchChoice;
        do {
            switchChoice = rand() % 3;
        } while (switchChoice == playerChoice || switchChoice == hostOpen);

        // Подсчет побед
        if (playerChoice == prizeDoor) {
            stayWins++;
        }
        if (switchChoice == prizeDoor) {
            switchWins++;
        }
    }

    // Вывод результатов
    cout << "Результаты после " << totalGames << " игр:" << endl;
    cout << "Победы без смены двери: " << stayWins << " (" 
         << (stayWins * 100.0 / totalGames) << "%)" << endl;
    cout << "Победы при смене двери: " << switchWins << " (" 
         << (switchWins * 100.0 / totalGames) << "%)" << endl;

    return 0;
}