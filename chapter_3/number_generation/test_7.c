#include <stdio.h>
#include <math.h>

int main(void)
{
    int a, b;
    scanf("%d, %d", &a, &b);

    // здесь продолжайте программу
    double tangens = (double)a / (double)b;
    printf("%.2f %.2f", tangens, atan(tangens));
    return 0;
}