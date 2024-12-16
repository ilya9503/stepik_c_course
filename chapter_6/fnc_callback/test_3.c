#include <stdio.h>
#define NUM     20
/*
здесь набор критериальных функций с сигнатурами:
int <имя функции>(int );
*/

int sum_ar(const int *ar, size_t len_ar, int (*check)(int))
{
    int sum = 0;
    for(int i = 0; i < len_ar ;++i)
        if(check(ar[i]))
            sum += ar[i];
    return sum;
}

int is_odd(int num)
{
    if(num % 2 != 0)
        return 1;
    else
        return 0;
}

int is_positive(int num)
{
    if(num > 0)
        return 1;
    else if(num == 0)
        return 2;
    else
        return 0;
}

int is_negative(int num)
{
    if(num < 0)
        return 1;
    else if(num == 0)
        return 2;
    else
        return 0;
}

int deflt(int num)
{
    return 1;
}

int main(void)
{
    // здесь массив указателей funcs на критериальные функции
    int (*criterials[]) (int) = {is_odd, is_positive, is_negative, deflt}; // Массив из указателей на функции
    int marks[NUM] = {0};

    int item = 0;
    scanf("%d", &item); // выбор критерия суммирования

    int x, i = 0;
    while(scanf("%d", &x) == 1 && i < NUM) {
        // здесь формирование значений массива marks
        marks[i] = x;
        ++i;
    }

    int sum = 0; // переменная для хранения суммы
    switch(item) {
        case 1:
            sum = sum_ar(marks, NUM, criterials[0]); // здесь вызов функции sum_ar с первой критериальной функцией
            break;
        case 2:
            sum = sum_ar(marks, NUM, criterials[1]); // здесь вызов функции sum_ar со второй критериальной функцией
            break;
        case 3:
            sum = sum_ar(marks, NUM, criterials[2]); // здесь вызов функции sum_ar с третьей критериальной функцией
            break;
        default:
            sum = sum_ar(marks, NUM, criterials[3]); // здесь вызов функции sum_ar с критериальной функцией deflt
    }

    printf("%d", sum);

    return 0;
}