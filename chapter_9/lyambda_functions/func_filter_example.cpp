//9.16.4

#include <iostream>

int main(void)
{
    // массив из указателей на функцию
    bool (*func_filter[])(int) {[](int num){return num % 2 == 0;},
                                [](int num){return num < 0;},
                                [](int num){return num > 0;}};

    int a;

    std::cin >> a;
    
    bool res = func_filter[1](a);

    std::cout << res << std::endl;
    
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}