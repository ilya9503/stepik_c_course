#include <stdio.h>

double get_mean2(int a, int b)
{
    return ((double)a + (double) b) / 2;
}

int main(void)
{
    // здесь продолжайте функцию main
    int a, b;
    double res;
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Incorrect input!");
        return 0;
    }

    res = get_mean2(a, b);
    printf("%.1f", res);


    return 0;
}