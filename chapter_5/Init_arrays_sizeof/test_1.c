/*
    Выведите в консоль в одну строчку через пробел значения его элементов в обратном
    порядке с точностью до десятых
*/
#include <stdio.h>

short marks[] = {1, 2, 3, 4, 5};
float pows[] = {1.1, 2.2, 3.3, 4.4, 5.5};

int main(void)
{
    // здесь продолжайте программу
    // printf("%d %d\n", sizeof marks / sizeof *marks, sizeof marks);

    for(int i = (sizeof pows / sizeof *pows) - 1; i >= 0 ;--i)
        printf("%.1f ", pows[i]);

    return 0;
}