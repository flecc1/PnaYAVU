#ifndef FILE_EXCEPTION_H
#define FILE_EXCEPTION_H

#include "excep.h"

/**
 * @class FileException
 * @brief Класс исключений для файловых операций
 * 
 * Наследуется от My_exception и добавляет информацию о файле:
 * тип ошибки, имя файла и тип операции (чтение/запись/открытие).
 * Используется для обработки ошибок при работе с файлами.
 */
class FileException : public My_exception
{
    char error_type[S];
    char filename[S];
    char operation[S];
    
public:
    FileException() : My_exception()
    {
        strcpy(error_type, "");
        strcpy(filename, "");
        strcpy(operation, "");
    }
    
    FileException(int code, const char *error_type, const char* message, 
                  const char* filename = "", const char* operation = "") 
        : My_exception(code, message)
    {
        strncpy(this->error_type, error_type, S - 1);
        this->error_type[S - 1] = '\0';
        
        strncpy(this->filename, filename, S - 1);
        this->filename[S - 1] = '\0';
        
        strncpy(this->operation, operation, S - 1);
        this->operation[S - 1] = '\0';
    }
    
    FileException(const FileException& other) : My_exception(other) 
    {
        strncpy(error_type, other.error_type, S - 1);
        error_type[S - 1] = '\0';
        
        strncpy(filename, other.filename, S - 1);
        filename[S - 1] = '\0';
        
        strncpy(operation, other.operation, S - 1);
        operation[S - 1] = '\0';
    }
    
    void printError() const override;
    
    const char* getErrorType() const { return error_type; }
    const char* getFilename() const { return filename; }
    const char* getOperation() const { return operation; }
};

#endif

