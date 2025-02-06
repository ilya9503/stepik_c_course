#include <iostream>

enum {max_length = 50};

using FIO_STR = char[max_length];
using FIO = struct {FIO_STR first; FIO_STR last; FIO_STR otch;};
using std::cin;

int main()
{
    // здесь продолжайте функцию main
    FIO fio;
    cin >> fio.first >> fio.otch >> fio.last;
    std::cout << fio.first << fio.otch << fio.last << std::endl; 

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}