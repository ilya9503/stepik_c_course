#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>

double norm(int a, int b);
double reley(double x1, double x2);

int main(void)
{
    // здесь продолжайте функцию main
    srand(time(NULL));
//    double y = norm(-2, 10);
    double y = reley(norm(0, 5), norm(0, 5));
//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}

double norm(int a, int b)
{
    int N = 100;
    double num = 0;
    for(int i = 1; i <= 100; ++i) {
        num += rand() % b + a;
    }

    return num / N;
}

double reley(double x1, double x2)
{
    double res = 0;
    res = pow(x1 * x1 + x2 * x2, 0.5);
}