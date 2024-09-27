#include <stdio.h>

int main(void)
{
    double height, a;

    int res = scanf("%lf %lf", &height, &a);
    if (res != 2)
    {
        printf("Error");
        return 0;   // выход из main(), завершение программы
    }
    
    double sq = height * a / 2.0;
    printf("Площадь треугольника = %.2lf\n", sq);


    return 0;
}