/*
    Передача аргументов в параметры функции по значению
    Передача аргументов в параметры функции по ссылке
    В функцию передается копия, но по ссылке передается копия адреса переменной
*/
#include <stdio.h>
#define COLS    3

void swap_2(int*a, int*b);

int sum_ar(const short* arr, int length);   // const short* arr = const short arr[]. Эквивалентная запись указателя на массив

const char* find_space(const char* buf);

void show_ar2D(const short (*ar)[COLS], int rows);

int main(void)
{
    int a = 5, b = 10;
    printf("%d %d\n", a, b);
    swap_2(&a, &b);
    printf("%d %d\n", a, b);


    short ar[] = {1, 2, 3, 4, 5};
    int res = sum_ar(ar, sizeof(ar) / sizeof(*ar));
    printf("Сумма эл-тов массива = %d\n", res);


    char str[] = "Hello World!";
    const char* res_ch = find_space(str);
    printf("res_ch = %s\n", res_ch);

    short ar_2[][COLS] = {{1, 2, 3}, {4, 5, 6}};
    show_ar2D(ar_2, sizeof(ar_2) / sizeof(*ar_2));

    return 0;
}

/*==================================    БИБЛИОТЕКА  ============================================================================================*/

// Замена значений переменных с помощью указателей
void swap_2(int*a, int*b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Сумма эл-тов массива. Причем параметр массива используется только для чтения
int sum_ar(const short* arr, int length)
{
    // Length необходим, тк мы не можем сделать sizeof от адреса массива (внутри функции)
    int res = 0;
    for(int i = 0; i < length; ++i)
        res += arr[i];  // arr - адрес массива. Через операцию [] обращаемся к эл-там
    return res;
}

// Поиск пробела в строке. Передаем указатель на символ, его же и возвращаем
const char* find_space(const char* buf)
{
    while (*buf != '\0') {
        if(*buf == ' ')
            return buf;
        buf++;
    } 
}

// Выводим двумерного массива в консоль.
void show_ar2D(const short (*ar)[COLS], int rows)
{
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < COLS; ++j)
            printf("%d ", ar[i][j]);
        putchar('\n');
    }
}