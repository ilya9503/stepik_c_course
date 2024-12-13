#include <stdio.h>
 
#define SIZE        10
/*
    Выбираем только четные значения из массива src в массив dst
    Используем другую функцию is_even как параметр (указатель на функцию is_even)
*/ 
void filter(int dst[], size_t size_dst, 
            const int src[], size_t size_src, 
            int (*is_correct)(int))
{
    for(int i = 0; i < size_dst; ++i)
              dst[i] = 0;    
    for(int i = 0, j = 0; i < size_src; ++i)
              if(is_correct(src[i]))
                       dst[j++] = src[i];
}

// Проверка четности 
int is_even(int x)
{
    return x % 2 == 0;
}

// Проверка положительности
int is_positive(int x)
{
    return x > 0;
}

// Проверка нечетности
int is_odd(int x)
{
    return x % 2 != 0;
}
 
int main(void) 
{
    int digits[] = {-3, 4, 10, 11, -5, 3};
    int result[SIZE];
    int (*criterials[]) (int) = {is_even, is_odd, is_positive}; // Массив из указателей на функции

    // Вызываем функцию с параметром в виде указателя на другую функцию is_even()
    // Можно легко подменить аргумент параметра на другой (подставить другую функцию)
    filter(result, SIZE, digits, sizeof(digits) / sizeof(*digits), is_positive);
    // Массив из указателей на функции. Подставляем эл-ты массива (1 из нескольких функций-аргументов)
    filter(result, SIZE, digits, sizeof(digits) / sizeof(*digits), criterials[1]);
    
    for(int i = 0; i < SIZE; ++i)
        printf("%d ", result[i]);

    return 0;
}