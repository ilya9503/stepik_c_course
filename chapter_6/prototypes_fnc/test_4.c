#include <stdio.h>
#define PI  3.1415

double circle_len(double);

int main(void)
{
    // здесь продолжайте функцию main
    double R;
    if (scanf("%lf", &R) != 1) {
        printf("Incorrect input!");
        return 0;
    }

    printf("%.2f", circle_len(R));
    return 0;
}

// Радиус круга
double circle_len(double R)
{
    return 2 * PI * R;
}