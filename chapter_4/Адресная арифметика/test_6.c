/*
    Напишите программу, которая читает из входного потока четыре целых числа
    a, b, c, d, записанных в одну строчку через пробел.
    Необходимо определить войдет ли в конверт с внутренними размерами a и b см
    прямоугольная открытка с размерами с и d см.
    Для размещения открытки в конверте необходим зазор в 0,5 см с каждой стороны.
    Вывести в консоль "yes", если входит и "no" если не входит.
*/
#include <stdio.h>

int main(void)
{
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if(((b-c)>=1) && ((a-d)>=1))
        printf("yes");
    else if(((b-d)>=1) && ((a-c)>=1))
        printf("yes");
    else
        printf("no");

    return 0;
}