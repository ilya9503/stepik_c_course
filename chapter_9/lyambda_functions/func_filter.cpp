/*
    std::function - обобщенный контейнер для хранения функций, лямбд и функциональных объектов
*/
#include <iostream>
#include <functional>   // работа с функциональными объектами

int main(void)
{
    // здесь продолжайте функцию main
    std::function<int(int)> func_filter[] {
        [](int x) -> int {return !(x % 2);},
        [](int x) -> int {return x < 0;},
        [](int x) -> int {return x > 0;}
    };

    int n;
    std::cin >> n;
    std::cout << func_filter[1](n) << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}