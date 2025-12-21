#ifndef FILE_BIN_TPP
#define FILE_BIN_TPP

#include "../headers/file_bin.h"
#include "../headers/excep_vvoda.h"
// file-specific exception
#include "../headers/file_exception.h"

template<class T>
File_bin<T>::File_bin(const string& fname) : File<T>(fname) {}

template<class T>
void File_bin<T>::write(Ochered<T>& data) {
    try {
        ofstream out(this->filename, ios::binary);
        if (!out.is_open()) {
            throw File_exception(110, "Не удалось открыть файл для записи");
        }
        
        int size = data.getSize();
        out.write(reinterpret_cast<const char*>(&size), sizeof(size));
        
        for (int i = 0; i < size; i++) {
            const T& obj = data[i];
            out.write(reinterpret_cast<const char*>(&obj), sizeof(obj));
        }
        
        if (!out.good()) {
            throw File_exception(111, "Ошибка при записи в файл");
        }
        
        out.close();
    } catch (const File_exception& e) {
        throw;
    } catch (const exception& e) {
        throw File_exception(112, e.what());
    }
}

template<class T>
Ochered<T> File_bin<T>::read() {
    try {
        Ochered<T> result;
        ifstream in(this->filename, ios::binary);
        
        if (!in.is_open()) {
            throw File_exception(113, "Не удалось открыть файл для чтения");
        }
        
        int size;
        in.read(reinterpret_cast<char*>(&size), sizeof(size));
        
        if (!in.good()) {
            throw File_exception(114, "Ошибка при чтении размера данных");
        }
        
        for (int i = 0; i < size; i++) {
            T obj;
            in.read(reinterpret_cast<char*>(&obj), sizeof(obj));
            
            if (!in.good() && i < size - 1) {
                throw File_exception(115, "Ошибка при чтении данных");
            }
            
            result.pushback(obj);
        }
        
        in.close();
        return result;
    } catch (const File_exception& e) {
        throw;
    } catch (const exception& e) {
        throw File_exception(116, e.what());
    }
}

template<class T>
void File_bin<T>::display() {
    try {
        ifstream in(this->filename, ios::binary | ios::ate);
        if (!in.is_open()) {
            throw File_exception(117, "Не удалось открыть файл для просмотра");
        }
        
        streamsize size = in.tellg();
        in.seekg(0, ios::beg);
        
        cout << "\n=== Бинарный файл " << this->filename << " ===" << endl;
        cout << "Размер файла: " << size << " байт" << endl;
        cout << "Для просмотра содержимого используйте hex-редактор" << endl;
        
        in.close();
    } catch (const File_exception& e) {
        throw;
    } catch (const exception& e) {
        throw File_exception(118, e.what());
    }
}

#endif