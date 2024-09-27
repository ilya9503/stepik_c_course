#include <stdio.h>

int main (void)
{
    long long var_i = -12083456456345;
    long double var_d = 464356345.4363456;
    short var_h = 100;

    // % - спецификатор преобразования. Тип аргумента должен быть согласован 
    printf("Long Long: %lld\n", var_i);
    printf("Long Double: %Lf\n", var_d);
    printf("var_i = %lld, var_d = %Lf, var_h = %d\n", var_i, var_d, var_h);

    // Выравнивание по правому + и левому - краю. Число - минимальная ширина поля
    printf("[%-10d]\n", var_h);
    printf("[%-20Lf]\n", var_d);

    return 0;
}