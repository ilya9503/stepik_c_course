/*
    Указатель на функцию синтаксис:
    <тип> (*<имя указателя>) (<типы параметров>);
    требуется чтобы созпадал тип возвращаемого значения и типы параметров !!
*/
#include <stdio.h>

int sq_rect(int width, int height)
{
    return width * height;
}

int per_rect(int width, int height)
{
    return 2 * (width + height);
}

void print_hi(void)
{
    puts("Hi!");
}

int main(void)
{
    int (*ptr_func) (int, int);             // указатель на функцию
    ptr_func = sq_rect;

    int res = ptr_func(2, 3);               // вызов функции с помощью указателя

    void (*ptr_hi) (void);
    ptr_hi = print_hi;
    ptr_hi();

    printf("ptr_func(2, 3) = %d\n", res);
    printf("sq_rect = %p\n", sq_rect);      // Имя функции = указатель на функцию
    return 0;
}