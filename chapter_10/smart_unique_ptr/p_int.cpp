#include <iostream>
#include <memory>

int main(void)
{
    int x;
    std::cin >> x;

    // здесь продолжайте функцию main
    std::unique_ptr<int> p_int {std::make_unique<int>(x)};
    std::cout << *p_int << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}