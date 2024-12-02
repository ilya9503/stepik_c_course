#include <stdio.h>
#include <math.h>

double get_length(int x, int y)
{
    return pow((double)(x*x+y*y), 0.5);
}

int main(void)
{
    // здесь продолжайте функцию main
    int x, y;

    if (scanf("%d %d", &x, &y) != 2) {
        printf("Incorrect input!");
        return 0;
    }

    printf("%.2f", get_length(x, y));

    return 0;
}