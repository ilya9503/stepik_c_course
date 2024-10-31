/*
    Вставка значения в массив
    Алгоритм вставки
*/
#include <stdio.h>

#define TOTAL_MARKS     10

int main(void)
{

//============================ Вставка значения в массив ================================================

    int marks[TOTAL_MARKS] = {3, 2, 5};
    int insert_index = 2;   // вставляем недостающее зн-е в поз. 2

    // массив до вставки
    for (int i = 0; i < TOTAL_MARKS; ++i)
        printf("%d ", marks[i]);
    printf("\n");

    // сдвигаем все эл-ты на 1 вправо до 2 позиции(10 элемент исчезнет)
    for(int i = TOTAL_MARKS-1; i > insert_index; --i) {
        marks[i] = marks[i-1];
        printf("marks[%d] = marks[%d]\n", i, i-1);
    }

    // вставляем нужное зн-е на 2 позицию 
    marks[insert_index] = 4;

    // массив после вставки
    for (int i = 0; i < TOTAL_MARKS; ++i)
        printf("%d ", marks[i]);
    

    return 0;
}