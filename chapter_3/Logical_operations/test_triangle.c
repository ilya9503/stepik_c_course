#include <stdio.h>

int main(void)
{
    double a, b, c;
    scanf("%lf, %lf, %lf", &a, &b, &c);

    /* Могут ли стороны a, b, c образовать треугольник? (a < c + b) || (b < c + a) || */
    if ((c < a + b))
        printf("yes");
    else
        printf("no");

    return 0;
}