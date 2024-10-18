#include <stdio.h>

int main(void)
{
    int init, k;


    scanf("%d", &init);
    k = init;

    // здесь продолжайте программу
    int *ptr_k = &k;
    *ptr_k += 10;
    printf("%d", k);
//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}