/*
    Продолжите программу, в которой определена макро-функция с именем GIPOT,
    вычисляющая длину гипотенузы по двум катетам прямоугольного треугольника.
    Вызовите макрос GIPOT для величин a+3 и b-2.
    Результат вызова сохраните в переменной length.
    Выведите в консоль значение переменной length с точностью до сотых.
*/
#include <stdio.h>
#include <math.h>

// здесь объявляйте макро-функцию
// Можно использовать встроенную функцию double hypot  (double x, double y);
#define GIPOT(A, B) (sqrt((double)((A)*(A) + (B)*(B))))

int main(void)
{
    int a, b;
    if(scanf("%d, %d", &a, &b) != 2) {
        printf("Input error");
        return 0;
    }

    // здесь продолжайте программу
    double length = GIPOT(a+3, b-2);
    printf("%.2f", length);

    return 0;
}