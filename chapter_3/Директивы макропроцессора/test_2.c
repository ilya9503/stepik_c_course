#include <stdio.h>

// здесь определяйте макрос PI
#define PI      3.1415
#define GRAD    180 / PI    // здесь формула перевода из радиан в градусы

int main(void)
{
    double rad;
    scanf("%lf", &rad);

    // здесь продолжайте программу
    double grad = rad * GRAD;
    printf("%.2f", grad);

    return 0;
}