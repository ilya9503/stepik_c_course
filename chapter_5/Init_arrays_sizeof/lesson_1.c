/*
    Инициализация массива может значительно увеличивать время исполнения программы,
        при длине массива >1000 эл-тов
    Инициализировать массив лучше 1 раз, глобально. Чтобы не повторять инициализацию
        в функции
    
    Compile time - program compilation
    Compiler phases:
         syntax analysis
         semantic analysis
         and code generation
    Runtime - program execution
    JIT compilers VS AOT compilers

    Runtime constant - These are the constants whose respective values can only be
        known or computed at the time of running of source code.
        Пример - константа которую вводим с клавиатуры

    Compiletime constant - the constants whose respective value is known
        or computed at the time of compilation of source code
        Пример - константа, которая инициализирована в коде программы и известна перед
        исполнением программы
*/
#include <stdio.h>
#include <stdlib.h>

int month[] = {31, 28, 30, 31, 28, 30, 31, 28, 30, 31, 28, 30};

int main(void)
{
    int val = -5;
    int cords[] = {10, -2, 30, val, abs(val)};
    // Инициализация в стандарте С99
    short digits[10] = {-1, [2] = 5, 18, [9] = -1};
    
    /*
        sizeof(cords) - размер массива в байтах
        sizeof(cords[0]) - размер первого элемента в байтах
        sizeof(cords) / sizeof(cords[0]) - размер массива (кол-во ячеек)
    */
    for (int i = 0; i < sizeof(digits) / sizeof(digits[0]); ++i) {
        printf("%d ", digits[i]);
    }
    sizeof digits;

    return 0;
}