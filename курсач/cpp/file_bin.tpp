#include "../headers/file_bin.h"
#include "../headers/excep.h"
#include "../headers/file_exception.h"
#include <fstream>

template<class T>
File_bin<T>::File_bin(const string& fname) : File<T>(fname) {}

template<class T>
void File_bin<T>::write(Ochered<T>& data) {
    try {
        ofstream out(this->filename, ios::binary);
        if (!out.is_open()) {
            throw FileException(110, "FILE_OPEN_ERROR", 
                "Не удалось открыть файл для записи", 
                this->filename.c_str(), "write");
        }
        
        int size = data.getSize();
        out.write(reinterpret_cast<const char*>(&size), sizeof(size));
        
        for (int i = 0; i < size; i++) {
            const T& obj = data[i];
            out.write(reinterpret_cast<const char*>(&obj), sizeof(obj));
        }
        
        if (!out.good()) {
            throw FileException(111, "FILE_WRITE_ERROR", 
                "Ошибка при записи в файл", 
                this->filename.c_str(), "write");
        }
        
        out.close();
    } catch (const FileException& e) {
        throw;
    } catch (const My_exception& e) {
        throw FileException(112, "FILE_WRITE_ERROR", e.getMessage(), 
            this->filename.c_str(), "write");
    } catch (const exception& e) {
        throw FileException(112, "FILE_WRITE_ERROR", e.what(), 
            this->filename.c_str(), "write");
    }
}

template<class T>
Ochered<T> File_bin<T>::read() {
    try {
        Ochered<T> result;
        ifstream in(this->filename, ios::binary);
        
        if (!in.is_open()) {
            throw FileException(113, "FILE_OPEN_ERROR", 
                "Не удалось открыть файл для чтения", 
                this->filename.c_str(), "read");
        }
        
        int size;
        in.read(reinterpret_cast<char*>(&size), sizeof(size));
        
        if (!in.good()) {
            throw FileException(114, "FILE_READ_ERROR", 
                "Ошибка при чтении размера данных", 
                this->filename.c_str(), "read");
        }
        
        for (int i = 0; i < size; i++) {
            T obj;
            in.read(reinterpret_cast<char*>(&obj), sizeof(obj));
            
            if (!in.good() && i < size - 1) {
                throw FileException(115, "FILE_READ_ERROR", 
                    ("Ошибка при чтении данных (элемент " + to_string(i) + ")").c_str(), 
                    this->filename.c_str(), "read");
            }
            
            result.pushback(obj);
        }
        
        in.close();
        return result;
    } catch (const FileException& e) {
        throw;
    } catch (const My_exception& e) {
        throw FileException(116, "FILE_READ_ERROR", e.getMessage(), 
            this->filename.c_str(), "read");
    } catch (const exception& e) {
        throw FileException(116, "FILE_READ_ERROR", e.what(), 
            this->filename.c_str(), "read");
    }
}

template<class T>
void File_bin<T>::display() {
    try {
        ifstream in(this->filename, ios::binary | ios::ate);
        if (!in.is_open()) {
            throw FileException(117, "FILE_OPEN_ERROR", 
                "Не удалось открыть файл для просмотра", 
                this->filename.c_str(), "display");
        }
        
        streamsize size = in.tellg();
        in.seekg(0, ios::beg);
        
        cout << "\n=== Бинарный файл " << this->filename << " ===" << endl;
        cout << "Размер файла: " << size << " байт" << endl;
        cout << "Для просмотра содержимого используйте hex-редактор" << endl;
        
        in.close();
    } catch (const FileException& e) {
        throw;
    } catch (const My_exception& e) {
        throw FileException(118, "FILE_DISPLAY_ERROR", e.getMessage(), 
            this->filename.c_str(), "display");
    } catch (const exception& e) {
        throw FileException(118, "FILE_DISPLAY_ERROR", e.what(), 
            this->filename.c_str(), "display");
    }
}

