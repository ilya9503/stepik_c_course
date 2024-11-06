#include <stdio.h>

#define TOTAL     20

int main(void)
{
    float ws[TOTAL] = {0.0f};
    size_t count = 0;
    size_t sz_ar = sizeof(ws) / sizeof(*ws);

    while(count < sz_ar && scanf("%f", &ws[count]) == 1)
        count++;

    // здесь продолжайте программу
    int pos;    // индекс минимального элемента
        // Перебираем исходный массив a[size]
    for (int i = 0; i < count; ++i) {
        pos = i;
        // Выбираем MIN индекс массива
        for (int j = i+1; j < count; ++j) {
            // Если след. ячейка < текущей, сдвигаемся вправо
            if(ws[pos] > ws[j])
                pos = j;
        }
        // Если MIN в любой другой ячейке, то меняем ее с текущей
        if(pos != i) {
            // Меняем эл-ты местами
            float t = ws[i];
            ws[i] = ws[pos];
            ws[pos] = t;
        }
    }

    // Массив после сортировки
    for (int i = 0; i < count; ++i)
        printf("%.2f ", ws[i]);

    return 0;
}