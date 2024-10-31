/*
    Алгоритм сортировки выбором (selection sort):
        1. Находим MIN эл-т и меняем его с первым эл-том 
        2. Сдвигаемся на 1 эл-т вправо
        3. Находим MIN эл-т и меняем его с первым эл-том
        4. Повторяем пока не дойдем до последнего эл-та
*/
#include <stdio.h>

int main(void)
{
    char a[] = {-3, 5, 0, -8, 1, 10};
    int size = sizeof(a) / sizeof(a[0]);
    int pos;    // индекс минимального элемента

    // Массив до сортировки
    for (int i = 0; i < size; ++i)
        printf("%d ", a[i]);
    printf("\n");

    // Перебираем исходный массив a[size]
    for (int i = 0; i < size-1; ++i) {
        pos = i;
        // Выбираем MIN индекс массива
        for (int j = i+1; j < size; ++j) {
            // Если след. ячейка < текущей, сдвигаемся вправо
            if(a[pos] > a[j])
                pos = j;
        }
        // Если MIN в любой другой ячейке, то меняем ее с текущей
        if(pos != i) {
            // Меняем эл-ты местами
            int t = a[i];
            a[i] = a[pos];
            a[pos] = t;
        }
    }

    // Массив после сортировки
    for (int i = 0; i < size; ++i)
        printf("%d ", a[i]);
    
    return 0;
}