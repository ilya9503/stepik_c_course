#include <iostream>
#include <math.h>
#include <iomanip>


int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;

    // здесь продолжайте программу
    auto sq_tr = [] (int a, int b, int c) {double p = (a+b+c) / 2.0; return sqrt(p*(p-a)*(p-b)*(p-c));};
    std::cout << std::fixed << std::setprecision(2) << sq_tr(a, b, c) << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}