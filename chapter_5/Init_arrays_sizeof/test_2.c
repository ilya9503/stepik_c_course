#include <stdio.h>

int main(void)
{
    // здесь продолжайте программу
//    long digits[128] = {[16] = 4, [32] = 5, [64] = 6};
    short ar_rnd[64] = {0};
    for(int i = 0; i < 5; ++i) {
        scanf("%hd ", &ar_rnd[i]);
        printf("%d ", ar_rnd[i]);
    }
//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}