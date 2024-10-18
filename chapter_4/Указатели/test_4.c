#include <stdio.h>

int main(void)
{
    short a, b, init_a, init_b;

    scanf("%hd, %hd", &a, &b);
    init_a = a; init_b = b;

    // здесь продолжайте программу
    short *ptr_a = &a;
    short *ptr_b = &b;
    *ptr_a = init_b;
    *ptr_b = init_a;
    printf("a = %d, b = %d", a, b);
//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}