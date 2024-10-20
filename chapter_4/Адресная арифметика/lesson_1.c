#include <stdio.h>

int main(void)
{
    short ar[10];       // short = 2 байта. 1 блок данных = 2 ячейки памяти
    short *ptr = ar;    // адрес 0-ого элемента массива
    short *p = &ar[3];  // адрес 4-ого элемента массива

    printf("ptr = %u, p = %u\n", ptr, p);
    
    // такую операцию можно выполнять только с массивом одного типа данных
    int res = p - ptr;  // 3 блока данных = 6 ячеек памяти / 2 байта

    printf("res = %u\n", res);

    return 0;
}