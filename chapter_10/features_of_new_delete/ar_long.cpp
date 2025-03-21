#include <iostream>

int main(void)
{
    // здесь продолжайте функцию main
    long* ar_long {new long[1000]()};
    ar_long[4] = -7;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    // здесь освобождайте память из под массива
    delete [] ar_long;
    ar_long = nullptr;

    return 0;
}