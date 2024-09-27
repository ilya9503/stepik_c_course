#include <stdio.h>

int main(void)
{
    double a, b, c;
    scanf("%lf, %lf, %lf", &a, &b, &c);

    /* Алгоритм поиска минимального числа из 3-ех чисел */
    if (a < b && a < c)
        printf("%.2f", a);
    else if (b < a && b < c)
            printf("%.2f", b);
    else if (c < a && c < b)
            printf("%.2f", c);

    return 0;
}