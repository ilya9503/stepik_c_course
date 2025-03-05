#include <iostream>

int main(void)
{
    // здесь продолжайте функцию main
    int w, h;
    std::cin >> w >> h;
    auto sum_ab = [=](){return w + h;};
    std::cout << sum_ab() << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}