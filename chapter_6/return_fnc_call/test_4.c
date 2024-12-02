#include <stdio.h>

int is_range(double x, double a, double b)
{
    if(x > a && x < b)
        return 1;
    return 0;
}

int main(void)
{
    double x;
    while(scanf("%lf", &x) == 1) {
        // здесь продолжайте программу
        if(! is_range(x, -2.5, 3.5))
            printf("%.1f ", x);
    }

    return 0;
}