#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define     NUM     20

int main(void)
{
    // здесь продолжайте программу
    int lengths[NUM] = {0};     // исходный массив (локальный)
    int count = 0;
    while (scanf("%d ", &lengths[count]) && count <= NUM)
        ++count;
    int *ptr_lens = calloc(count, sizeof(int));
    memcpy(ptr_lens, lengths, count * sizeof(int));
    for (int i = 0; i < NUM; ++i)
        printf("%d ", ptr_lens[i]);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    // здесь освобождайте память
    free(ptr_lens);
    return 0;
}