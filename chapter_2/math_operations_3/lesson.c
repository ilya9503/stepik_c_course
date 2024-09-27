/*
    <выражение l-value> - это леводопустимое выражение
    <выражение l-value> = <выражение l-value> + 1;  тут используется 2 ячейки памяти
    <выражение l-value> += 1;                       тут используется 1 ячейка памяти
*/

#include <stdio.h>

int main(void)
{
    int count = 1;
    double var_d = 10.0;
    short p = 2;
    int a, b, c;

    // -= имеет наименьший приоритет
    count -= 3-5;
    var_d /= 3.0 + p;
    p *= 20 - 5;
    printf("count = %d, var_d = %.2f, p = %d\n", count, var_d, p);

    return 0;
}