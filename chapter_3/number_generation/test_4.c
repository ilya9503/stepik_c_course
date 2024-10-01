#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // здесь продолжайте программу
    srand(time(NULL));
    int r1 = rand();
    int r2 = rand();
    int r3 = rand();
    int r4 = rand();
    int r5 = rand();

//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}