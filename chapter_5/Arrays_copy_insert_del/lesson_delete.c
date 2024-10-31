/*
    Удаление значения из массива
    Алгоритм удаления значения из произвольного эл-ты массива
*/
#include <stdio.h>

#define TOTAL_MARKS     10

int main(void)
{

//============================ Удаление значения из массива ================================================

    int marks[TOTAL_MARKS] = {3, 2, 4, 5, 2, 4};
    int del_index = 3;   // удаляем зн-е из поз. 3

    // массив до удаления
    for (int i = 0; i < TOTAL_MARKS; ++i)
        printf("%d ", marks[i]);
    printf("\n");

    // сдвигаем все эл-ты массива влево на 1 эл-т. Последний и предпоследний эл-ты задублируются
    for(int i = del_index; i < TOTAL_MARKS-1; ++i) {
        marks[i] = marks[i+1];
        printf("marks[%d] = marks[%d]\n", i, i+1);
    }

    // массив после удаления
    for (int i = 0; i < TOTAL_MARKS; ++i)
        printf("%d ", marks[i]);
    

    return 0;
}