/*
    Напишите программу, которая читает из входного потока слово (фамилию студента), а затем, целые числа.
    Все записано в одну строчку через пробел.
    Максимальное количество чисел не более 20.
    Затем, представьте эти числа в виде строки формата:

    <фамилия>: <оценка 1>, <оценка 2>, ..., <оценка N>

    Оценки должны следовать в порядке их считывания. Выведите полученную строку в консоль.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SYMBOLS   100

int main(void)
{
    char grades[SYMBOLS] = {0};                 // исходная строка
    // Вводим строку из консоли 
    fgets(grades, sizeof(grades)-1, stdin);
    char* ptr_n = strrchr(grades, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    char grades_new[100] = {0};                 // новая строка
    char *ptr = strchr(grades, ' ');            // ищем фамилию в исходной строке
    strncpy(grades_new, grades, ptr-grades);    // добавляем в новую
    strcat(grades_new, ": ");

    while(*ptr != '\0') {   // ищем числа и добавляем их в строку с новым форматом
        int num = atoi(ptr);
        char num_ch[4] = {0};
        sprintf(num_ch, "%d, ", num);
        strcat(grades_new, num_ch);
        ptr += 2;
    }

    // находим последнюю запятую и удаляем
    ptr = strrchr(grades_new, ',');
    strncpy(grades, grades_new, ptr-grades_new);
    
    printf("%s", grades);

    return 0;
}