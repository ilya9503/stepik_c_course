/*
    sprintf() используется для преобразования чисел в строки
    atoi, atol, atoll, atof - перевод из строк в числа
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h> /* malloc, free, atoi, atol, atoll, atof     */

int main(void)
{
    int var_i = -123;
    char str_var[10];

    sprintf(str_var, "%d", var_i);

    puts(str_var);

    int a = atoi("123");
    long b = atol("234235354");
    long long c = atoll("23423535456456");
    double d = atof("4564.4545");
 
    printf("a = %d\nb = %ld\nc = %lld\nd = %f\n", a, b, c, d);

    return 0;
}