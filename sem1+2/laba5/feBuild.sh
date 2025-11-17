#!/bin/bash

CXX="g++"
CXXFLAGS="-std=c++11 -Wno-c++11-extensions -Iheaders"

printCodeExec() {
    echo -e "\e[32mExit code: $?\e[0m"
}

release() {
    mkdir -p build/obj build/binary build/prev
    [[ -f "build/listCPP.txt" ]] && mv build/listCPP.txt build/prev/listCPP.txt 2>/dev/null
    [[ -f "build/listH.txt" ]] && mv build/listH.txt build/prev/listH.txt 2>/dev/null
    find . -name "*.cpp" > build/listCPP.txt
    find . -name "*.h" > build/listH.txt

    if [ ! -s "build/listCPP.txt" ]; then
        echo "No CPP files"
        return 1
    fi

    echo "Found $(wc -l < build/listCPP.txt) .cpp files and $(wc -l < build/listH.txt) .h files"
}

# Функция для компиляции всех найденных .cpp файлов
compileAll() {
    echo -e "\e[34m➤ Compiling all .cpp files...\e[0m"
    
    # Компилируем все .cpp файлы
    while IFS= read -r cpp_file; do
        if [ -f "$cpp_file" ]; then
            filename=$(basename "$cpp_file" .cpp)
            echo "Compiling: $cpp_file"
            $CXX $CXXFLAGS -c "$cpp_file" -o "build/obj/${filename}.o"
            if [ $? -ne 0 ]; then
                echo -e "\e[31m✖ Failed to compile $cpp_file\e[0m"
                return 1
            fi
        fi
    done < build/listCPP.txt
    
    echo -e "\e[32m✔ All files compiled successfully\e[0m"
}

# Функция для перекомпиляции измененных файлов
recompileAll() {
    echo -e "\e[34m➤ Recompiling changed files...\e[0m"
    
    # Компилируем все .cpp файлы
    while IFS= read -r cpp_file; do
        if [ -f "$cpp_file" ]; then
            filename=$(basename "$cpp_file" .cpp)
            obj_file="build/obj/${filename}.o"
            
            # Компилируем если .o файла нет или .cpp файл новее
            if [ ! -f "$obj_file" ] || [ "$cpp_file" -nt "$obj_file" ]; then
                echo "Compiling: $cpp_file"
                $CXX $CXXFLAGS -c "$cpp_file" -o "$obj_file"
                if [ $? -ne 0 ]; then
                    echo -e "\e[31m✖ Failed to compile $cpp_file\e[0m"
                    return 1
                fi
            fi
        fi
    done < build/listCPP.txt
    
    echo -e "\e[32m✔ Recompilation completed\e[0m"
}

g() {
    echo -e "\e[34m➤ Linking...\e[0m"
    
    # Создаем массив из всех .o файлов
    obj_files=()
    while IFS= read -r cpp_file; do
        if [ -f "$cpp_file" ]; then
            filename=$(basename "$cpp_file" .cpp)
            obj_files+=("build/obj/${filename}.o")
        fi
    done < build/listCPP.txt
    
    # Линкуем все объектные файлы
    $CXX $CXXFLAGS "${obj_files[@]}" -o build/main
    if [ $? -eq 0 ]; then
        echo -e "\e[32m✔ Build successful!\e[0m"
    else
        echo -e "\e[31m✖ Build failed!\e[0m"
        return 1
    fi
}

# Main execution
release || exit 1
echo "Checking if compilation is needed..."

if [ ! -f "build/main" ]; then
    echo "First compilation..."
    compileAll || exit 1
    g || exit 1
    ./build/main
    jprintCodeExec


else
    updatedFiles=$(find . -name "*.cpp" -o -name "*.h" -newer build/main 2>/dev/null)
    if [[ -n "$updatedFiles" ]]; then
        echo "Changes detected, compiling..."
        recompileAll || exit 1
        g || exit 1
        ./build/main
        printCodeExec

    else
        echo "Compiling is not required"
        ./build/main
        printCodeExec
    fi
fi