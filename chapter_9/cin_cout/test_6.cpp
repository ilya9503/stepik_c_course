#include <iostream>
#include <cmath>
#include <iomanip>  // Для std::setprecision, std::fixed

double triangle_sq(int a, int b, int c)
{
    double p = (double)(a + b + c) / 2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    //  std::fixed - указывает, что число должно выводиться в фиксированном формате (не в экспоненциальном)
    //  std::setprecision(n) — задает количество знаков после запятой
    //  Альтернатива на Си использовать printf("%.3f\n", triangle_sq(a, b, c))

    std::cout << std::fixed << std::setprecision(2) << triangle_sq(a, b, c);
    return 0;
}