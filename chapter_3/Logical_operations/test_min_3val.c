#include <stdio.h>

int main(void)
{
    double a, b, c;
    scanf("%lf, %lf, %lf", &a, &b, &c);

    /* Алгоритм поиска минимального числа из 3-ех чисел */
    if (a == b) {
        if (a == c)
            printf("a = b = c = %.2f", a);  // а = b = с
        else {
            if (a < c)
                printf("a = b = %.2f", a);  // Минимальное а и b
            else
                printf("%.2f", c);      // Минимальное c
        }
    }
    else {
        if (a < b) {
            if (a == c)
                printf("a = c = %.2f", a);  // Минимальное а и c
            else {
                if (a < c)
                    printf("%.2f", a);  // Минимальное а
                else
                    printf("%.2f", c);  // Минимальное c
            }
        }
        else {
            if (b == c)
                printf("b = c = %.2f", b);  // Минимальное b и c
            else {
                if (b < c)
                    printf("%.2f", b);  // Минимальное b
                else
                    printf("%.2f", c);  // Минимальное c
            }
        }
    }

    return 0;
}