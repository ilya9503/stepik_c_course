/*
    Напишите программу, которая читает из входного потока целое число в переменную
    count типа int. В каждом байте переменной count нужно включить 3-й и 0-й биты
    (нумерация бит в байте: 7, 6, 5, 4, 3, 2, 1, 0).
    Вывести в консоль полученное значение count в виде одного целого числа.
*/
#include <stdio.h>

int main(void)
{
    int count;

    scanf("%d", &count);

    int *ptr_count = &count;            // 4 байта
    unsigned char *ptr_byte = (unsigned char*)ptr_count;  // 1 байт
    unsigned char mask = 9; // 9 = 0000 1001

    for (int i = 1; i <= sizeof(int); ++i) {
        *ptr_byte = *ptr_byte | 0b00001001; // используя константу
        ++ptr_byte;
    }


    printf("%d\n", count);
    
    
    return 0;
}