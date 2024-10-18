#include <stdio.h>

int main(void)
{
    short a, b;

    scanf("%hd, %hd", &a, &b);

    // здесь продолжайте программу
    short *ptr_a = &a;
    short *ptr_b = &b;
    int res = *ptr_a * *ptr_b;
    printf("%d", res);
//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}