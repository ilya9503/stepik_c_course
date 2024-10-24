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



    
    /*
        size_t
        Unsigned integral type
        Alias of one of the fundamental unsigned integer types.
        It is a type able to represent the size of any object in bytes:
        size_t is the type returned by the sizeof operator and is widely used
        in the standard library to represent sizes and counts.
    */
    // Определим размер массива marks в байтах. size_t - unsigned integral type
    size_t bytes_marks = sizeof(marks);
    // Вычислим размер массива в элементах типа int
    size_t size_marks = sizeof(marks) / sizeof(marks[0]);
    printf("%zu\n", size_marks);



    for(int i = 0; i < TOTAL_MARKS; ++i)
        printf("%d ", marks[i]);




    return 0;
}