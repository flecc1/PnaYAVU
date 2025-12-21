#ifndef FILE_TXT_TPP
#define FILE_TXT_TPP

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
            throw File_exception(100, "Не удалось открыть файл для записи");
        }
        
        for (int i = 0; i < data.getSize(); i++) {
            writeToFile(out, data[i]);  // Используем оператор для файлов
            if (i < data.getSize() - 1) {
                out << endl;
            }
        }
        
        out.close();
    } catch (const File_exception& e) {
        throw;
    } catch (const exception& e) {
        throw File_exception(101, e.what());
    }
}

template<class T>
Ochered<T> File_txt<T>::read() {
    try {
        Ochered<T> result;
        ifstream in(this->filename);
        
        if (!in.is_open()) {
            throw File_exception(102, "Не удалось открыть файл для чтения");
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
                    throw File_exception(103, 
                        ("Ошибка формата данных в строке " + to_string(line_num)).c_str());
                }
                
                result.pushback(obj);
            } catch (const File_exception& e) {
                // Пробрасываем исключение дальше
                throw;
            } catch (...) {
                throw File_exception(103, 
                    ("Неизвестная ошибка в строке " + to_string(line_num)).c_str());
            }
        }
        
        in.close();
        return result;
    } catch (const File_exception& e) {
        throw;
    } catch (const exception& e) {
        throw File_exception(104, e.what());
    }
}

template<class T>
void File_txt<T>::display() {
    try {
        ifstream in(this->filename);
        if (!in.is_open()) {
            throw File_exception(105, "Не удалось открыть файл для просмотра");
        }
        
        string line;
        cout << "\n=== Содержимое текстового файла " << this->filename << " ===" << endl;
        int line_num = 1;
        while (getline(in, line)) {
            cout << line_num++ << ": " << line << endl;
        }
        
        in.close();
    } catch (const File_exception& e) {
        throw;
    } catch (const exception& e) {
        throw File_exception(106, e.what());
    }
}

#endif