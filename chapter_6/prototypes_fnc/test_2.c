#include <stdio.h>

int calc_rect(int, int, int);

int main(void)
{
    int a, b, t;
    scanf("%d, %d, %d", &a, &b, &t);

    // здесь продолжайте программу
    printf("%d", calc_rect(a, b, t));

    return 0;
}

int calc_rect(int w, int h, int type)
{
    int res = 0;
    res = (type == 1) ? (w * h) : (2 * (w + h));
    return res;
}