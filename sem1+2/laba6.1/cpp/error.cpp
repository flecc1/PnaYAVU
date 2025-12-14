#include "../headers/excep_vvoda.h" 
#include <string>
#include <cctype>
#include <limits>

using namespace std;

inline void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
