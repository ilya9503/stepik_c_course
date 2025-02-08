/*
    Приведение типов указателей
    Далее, в С++ не принято использовать константу NULL для указания нулевого адреса.
    Пишется просто числовой литерал 0L. Начиная со стандарта С++11 был введен специальный
        «нулевой» указатель с ключевым словом nullptr
*/
#include <iostream>

int main()
{
    int* ptr_i = 0L;
    char* ptr_ch = 0L;

    //ptr_ch = ptr_i;             // В языке Си ок
    ptr_ch = (char *)ptr_i;     // В языке С++

    void* ptr_void = 0L;    // nullptr
    ptr_i = (int *)ptr_void;

    ptr_i = (int *)malloc(sizeof(int) * 5);     // возвращает void*, нужно приводить к int*

    ptr_ch = nullptr;
    printf("%p\n", ptr_ch);

    return 0;
}