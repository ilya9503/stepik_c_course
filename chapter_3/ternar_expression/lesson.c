#include <stdio.h>
#include <math.h>

int main(void)
{

    double a = 7.5, b = -3.43;
    /*
     Условный тернарный оператор <выражение 1> ? <выражение 2> : <выражение 3>
          Эквивалент             if (выражение 1) выражение 2; else выражение 3;
          Условный оператор ничего не возвращает
          Операция может быть частью выражения или аргументом функции
    */ 
    double max_ab = a > b ? a : b;

    double res_abs = (a < b) ? fabs(a) : fabs(b);

    printf("max_ab = %.2f\n", max_ab);
    printf("res_abs = %.2f\n", res_abs);

    int x = 7;
    // Тернанрная операция записана в качестве аргумента
    printf("x is %s digit\n", (x % 2 == 0) ? "even" : "odd");

    int a1 = 2, b1 = 3, c1 = -4;
    // Вложенная тернарная операция. Нахождение максимума среди 3-ех переменных
    int max = (a1 > b1) ? (a1 > c1 ? a1 : c1) : (b1 < c1) ? b1 : c1;
    printf("max = %d\n", max);

    return 0;
}