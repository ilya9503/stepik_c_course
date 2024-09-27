#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    /* Могут ли стороны a, b, c образовать треугольник? (a < c + b) || (b < c + a) || */
    if (a + b > c && b + c > a && c + a > b)
        printf("yes");
    else
        printf("no");

    (a + b > c && b + c > a && c + a > b) ? printf("yes") : printf("no");

    return 0;
}