/*
    Напишите следующую программу. Из входного потока читаются цифры (от 1 до 9),
    записанные через пробел, пока не встретится число 0.
    На основе этих цифр сформировать единое число.
    Например, если на вход поступают цифры:

    5 2 9 3 0

    то должно формироваться число:

    5293

    Выведите полученное число в консоль.

    Если цифра 0 встречается сразу (первая), то формируемая переменная должна
    принимать значение 0.

    P.S. Программу следует реализовать с использованием только текущих знаний
    (без массивов). 
*/
#include <stdio.h>

int main(void)
{
    int n, i = 0;

    for(; scanf("%d", &n) == 1 && n != 0; ){
        printf("%d", n);
        i = 1;
    }

    if(n == 0 && ! i)
        printf("%d", n);
    return 0;
}