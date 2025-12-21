// Сделаем реализацию идентичной laba6.1, адаптируя для FileException
#include "../headers/file_txt.h"
#include "../headers/excep_vvoda.h"
#include <sstream>
// file-specific exception
#include "../headers/file_exception.h"

template<class T>
File_txt<T>::File_txt(const string& fname) : File<T>(fname) {}

template<class T>
void File_txt<T>::write(Ochered<T>& data) {
    try {
        ofstream out(this->filename);
        if (!out.is_open()) {
            throw FileException(100, "FILE_OPEN_ERROR", "Не удалось открыть файл для записи", this->filename.c_str(), "write");
        }
        
        for (int i = 0; i < data.getSize(); i++) {
            writeToFile(out, data[i]);  // Используем оператор для файлов
            if (i < data.getSize() - 1) {
                out << endl;
            }
        }
        
        out.close();
    } catch (const FileException& e) {
        throw;
    } catch (const exception& e) {
        throw FileException(101, "FILE_WRITE_ERROR", e.what(), this->filename.c_str(), "write");
    }
}

template<class T>
Ochered<T> File_txt<T>::read() {
    try {
        Ochered<T> result;
        ifstream in(this->filename);
        
        if (!in.is_open()) {
            throw FileException(102, "FILE_OPEN_ERROR", "Не удалось открыть файл для чтения", this->filename.c_str(), "read");
        }
        
        // Проверяем, не пустой ли файл
        if (in.peek() == EOF) {
            in.close();
            return result;
        }
        
        string line;
        int line_num = 0;
        
        while (getline(in, line)) {
            line_num++;
            
            // Пропускаем пустые строки
            if (line.empty() || line.find_first_not_of(' ') == string::npos) {
                continue;
            }
            
            try {
                // Используем stringstream для разбора строки
                istringstream iss(line);
                T obj;
                
                // Используем оператор для чтения из файла
                readFromFile(iss, obj);
                
                // Проверяем успешность чтения
                if (iss.fail() && !iss.eof()) {
                    throw FileException(103, "FILE_FORMAT_ERROR", ("Ошибка формата данных в строке " + to_string(line_num)).c_str(), this->filename.c_str(), "read");
                }
                
                result.pushback(obj);
            } catch (const FileException& e) {
                // Пробрасываем исключение дальше
                throw;
            } catch (...) {
                throw FileException(103, "FILE_READ_ERROR", ("Неизвестная ошибка в строке " + to_string(line_num)).c_str(), this->filename.c_str(), "read");
            }
        }
        
        in.close();
        return result;
    } catch (const FileException& e) {
        throw;
    } catch (const exception& e) {
        throw FileException(104, "FILE_READ_ERROR", e.what(), this->filename.c_str(), "read");
    }
}

template<class T>
void File_txt<T>::display() {
    try {
        ifstream in(this->filename);
        if (!in.is_open()) {
            throw FileException(105, "FILE_OPEN_ERROR", "Не удалось открыть файл для просмотра", this->filename.c_str(), "display");
        }
        
        string line;
        cout << "\n=== Содержимое текстового файла " << this->filename << " ===" << endl;
        int line_num = 1;
        while (getline(in, line)) {
            cout << line_num++ << ": " << line << endl;
        }
        
        in.close();
    } catch (const FileException& e) {
        throw;
    } catch (const exception& e) {
        throw FileException(106, "FILE_DISPLAY_ERROR", e.what(), this->filename.c_str(), "display");
    }
}

