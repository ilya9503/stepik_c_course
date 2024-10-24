#include <stdio.h>

#define TOTAL   5

int main(void)
{
    // здесь продолжайте программу
    int ar_1[TOTAL], ar_2[TOTAL*2];

    for (int i = 0; i < TOTAL; ++i) {
        scanf("%d ", &ar_1[i]);
        ar_2[i] = ar_1[i];
        ar_2[TOTAL+i] = -1;
    }    

//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}