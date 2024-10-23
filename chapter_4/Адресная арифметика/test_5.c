/*
    Напишите программу, которая читает из входного потока целое число
    в переменную count типа int. В каждом байте переменной count нужно выключить
    7-й, 6-й и 1-й биты (нумерация бит в байте: 7, 6, 5, 4, 3, 2, 1, 0).
    Вывести в консоль полученное значение count в виде одного целого числа
    0011 1101 = 61
*/
#include <stdio.h>

int main(void)
{
    int count;

    scanf("%d", &count);

    int *ptr_count = &count;            // 4 байта
    unsigned char *ptr_byte = (unsigned char*)ptr_count;  // 1 байт
    unsigned char mask = 61; // 0011 1101 = 61

    for (int i = 1; i <= sizeof(int); ++i) {
        *ptr_byte &= mask; // используя переменную
        ++ptr_byte;
    }


    printf("%d\n", count);
    
    
    return 0;
}