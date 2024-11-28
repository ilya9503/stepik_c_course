/*
    Напишите программу, которая читает строку, представленную в формате:

    <имя студента>: <оценка 1>, <оценка 2>, ..., <оценка N>

    Все оценки представлены целыми числами. Количество оценок может быть разным у разных студентов,
    но не более 20.

    Необходимо вычислить среднее арифметическое оценок и полученное вещественное число вывести в консоль
    с точностью до тысячных.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SYMBOLS   100

int main(void)
{
    char grades[SYMBOLS] = {0};
    // Вводим строку из консоли 
    fgets(grades, sizeof(grades)-1, stdin);
    char* ptr_n = strrchr(grades, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    // Балакирев: 2, 2, 2, 5, 5, 2, 2, 5
    int sum = 0, count = 0;
    char *ptr_sub = strpbrk(grades, ":,");
    
    while (ptr_sub != NULL) {
        int grade = atoi(ptr_sub+1);
        ptr_sub = strpbrk(ptr_sub+1, ":,");
        sum += grade;
        count++;
    }

    printf("%.3f", (double)sum / (double)count);
    
    return 0;
}