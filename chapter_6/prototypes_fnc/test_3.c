#include <stdio.h>

int get_max(int, int);
int get_min(int, int);

int main(void)
{
    int a, b, t;
    scanf("%d, %d, %d", &a, &b, &t);

    // здесь продолжайте программу
    printf("%d", (t == 1) ? get_max(a, b) : get_min(a, b));

    return 0;
}

int get_max(int a, int b)
{
    return (a > b) ? a : b;
}

int get_min(int a, int b)
{
    return (a < b) ? a : b;
}