/*
    Директива typedef позволяет задавать пользовательское имя типа.
        Попросту говоря, она любой тип данных позволяет представить другим именем.
    Разница #define и typedef:
        Директива #define обрабатывается текстовым препроцессором (подстановка текста)
        Директива typedef обрабатывается компилятором, более безопасный способ ()
*/
#include <stdio.h>
#include <stdlib.h>

#define PTR_INT int*
typedef int* PTR;
typedef unsigned char BYTE;

typedef enum {
    buffer_size = 2048,
    element_size = 12,
    window_size = 400
} SIZE_CONSTS;

int is_even(int x)
{
    return x % 2 == 0;
}

typedef int (*PTR_EVEN)(int);   // указатель на функцию типа int
typedef char (*PTR_AR_2D)[4];   // указательна 2-мерный массив

int main(void)
{
    BYTE byte;
    BYTE ch, var_ch = '\0';
    PTR_INT a, b;
    PTR ptr_a, ptr_b;   // int *ptr_a, *ptr_b

    SIZE_CONSTS sizes = window_size;
//    printf("%d\n", sizes);
//    printf("%d\n", buffer_size);



    PTR_EVEN func_even = is_even;
 
    printf("%d\n", func_even(2));
    printf("%d\n", func_even(3));


    char ar_2d[5][4] = {0};
    PTR_AR_2D ptr_2d = ar_2d;
    ar_2d[1][2] = 5;
    printf("%d\n", ptr_2d[1][2]);

    return 0;
}