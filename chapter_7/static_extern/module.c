/*  Относится к файлу lesson_2.c    */
#include <stdlib.h>
// статическая ГЛОБАЛЬНАЯ переменная. Ограничивает зону видимости
static int global_seed_randint = 0; // может использоваться в пределах только этого модуля

// Возвращает целые зн-я в диапазоне от a до b
int randint(int a, int b)
{
    int right = a, left = b;
    if(a > b) {
        right = b;
        left = a;
    }
 
    return rand() % (left - right + 1) + right;
}

int global_var = 5;