#include <stdio.h>
#include <math.h>

double get_geom(int, int);
long double my_sqrt(double x);

int main(void)
{
    int a, b;
//    scanf("%d, %d", &a, &b);

    // здесь продолжайте программу
    my_sqrt(25.0);
    printf("%.2f", get_geom(a, b));

    return 0;
}

// Вычисление среднего геометрического
double get_geom(int a, int b)
{
    return sqrt((double)(a*b));
}

// Нахождение квадратного корня
long double my_sqrt(double x) {
    double sqrt, temp;
    if (x != x || x < 0) {
        sqrt = 0. / 0.;
    }
    sqrt = x / 2;
    temp = 0;
    while (sqrt != temp) {
        temp = sqrt;
        sqrt = (x / temp + temp) / 2;
    }
    return sqrt;
}