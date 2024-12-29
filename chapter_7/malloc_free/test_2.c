#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define     NUM     20

int main(void)
{
    // здесь продолжайте программу
    double digits[NUM] = {0.0};     // исходный массив (локальный)
    int count = 0;
    while (scanf("%lf ", &digits[count]) && count <= NUM)
        ++count;

    size_t mem_size = sizeof(double) * count;
    double *ptr_d = malloc(mem_size);   // выделим память в куче для записи туда нового массива
    memcpy(ptr_d, digits, mem_size);

    for (int i = 0; i < count; ++i)
        printf("%.1f ", ptr_d[i]);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    // здесь освобождайте память
    free(ptr_d);
    return 0;
}