#include <iostream>

int main(void)
{
    // здесь продолжайте функцию main
    short* ptr_ar = new short[15];
    for(int i = 0; i < 15; ++i)
        ptr_ar[i] = -1;
    ptr_ar[4] = 100;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}