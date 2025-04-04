/*
     Напишите программу, которая читает из входного потока натуральное число n
     (целое, положительное). Затем, с помощью цикла do-while вычислить сумму следующего ряда:
    S = 1 + 1/2 + 1/3 .. + 1/n
    Значение суммы вывести в консоль в виде вещественного числа с точностью до сотых.
*/
#include <stdio.h>

int main(void)
{
    int n, i = 1;
    double s = 0;

    scanf("%d", &n);

    do {
        s += 1.0 / i;
//        printf("%.2f\n", s);
        ++i;
    } while (i <= n);

    printf("%.2f", s);
    
    return 0;
}