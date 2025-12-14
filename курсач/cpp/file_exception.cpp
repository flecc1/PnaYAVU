#include "../headers/file_exception.h"

/**
 * @brief Вывод информации об ошибке файловой операции
 * 
 * Выводит детальную информацию об ошибке:
 * - тип ошибки
 * - код ошибки
 * - сообщение
 * - имя файла (если указано)
 * - тип операции (если указан)
 */
void FileException::printError() const
{
    cout << "Ошибка файловой операции [" << error_type << "] " << error_code << ":" << endl;
    cout << message << endl;
    
    if (filename[0] != '\0') {
        cout << "Файл: " << filename << endl;
    }
    
    if (operation[0] != '\0') {
        cout << "Операция: " << operation << endl;
    }
}

