/*
    Операции с массивами: копирование, вставка, удаление, сортировка
    Массивы в Си - способ хранения зн-ий в непрерывной области памяти
    Массивы не являются структурой в языке Си
*/
#include <stdio.h>

int main(void)
{

//============================ Копируем массив func_1 в func 2 ================================================

    float func_1[100] = {2.4, -3.8, 0, 10.2, 11.78, -5.43};
    float func_2[50];

    int size_1 = sizeof(func_1) / sizeof(func_1[0]);
    int size_2 = sizeof(func_2) / sizeof(func_2[0]);
    int size = (size_1 < size_2) ? size_1 : size_2;

    for (int i = 0; i < size; ++i)
        func_2[i] = func_1[i];

    for (int i = 0; i < size; ++i)
        printf("%.2f ", func_2[i]);
    





    return 0;
}