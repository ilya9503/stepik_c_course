/*
    Массив в Си, не является структурой данных.
    Массив - непрерывная область памяти, контролирует которую,
        программист.
    Без инициализации в переменных хранится шум

    Память под массив выделяется в момент вызова функции, содержащей
    массив. Если не инициализировать, зн-я будут содержать мусор

    Компилятор MinGW очень не любит латинские символы в
    названиях пути к исходным/объектным кодам.
*/
#include <stdio.h>

#define TOTAL_MARKS     13  // Массив из 13 эл-тов [0-12]

int main(void)
{
    int marks[TOTAL_MARKS];
    marks[2] = 4;       // 3-ий элемент массива
    marks[0] = 2 * 3;   // 1-ый элемент массива
    marks[12] = 7 - 2;
//    marks[13] = 5;      // !! НЕДОПУСТИМО тк [13] = [0-12]
    // Индексы массива НЕ ДОЛЖНЫ выходить за допустимые пределы
    // 0 - 1-ый элемент. n-1 крайний элемент

    int x = marks[2];
//    printf("x = %d\n", x);

    for(int i = 0; i < TOTAL_MARKS; ++i)
        printf("%d ", marks[i]);




    return 0;
}