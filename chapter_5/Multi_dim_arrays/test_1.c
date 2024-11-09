/*
    Продолжите программу, которая читает из входного потока 9 целых чисел,
    записанных в одну строчку через пробел, и помещает их по порядку в двумерный целочисленный массив
    ar_2D размерностью 3 x 3.
    В тестах гарантируется наличие минимум 9 целых чисел.
*/
#include <stdio.h>
#define SIZE    3

int main(void)
{
    int ar_2D[SIZE][SIZE];
    size_t rows = sizeof(ar_2D) / sizeof(ar_2D[0]);         // количество строк i
    size_t cols = sizeof(ar_2D[0]) / sizeof(ar_2D[0][0]);   // количество столбцов j

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                scanf("%d ", &ar_2D[i][j]);
                printf("%d ", ar_2D[i][j]);
            }
            printf("\n");
        }

    return 0;
}