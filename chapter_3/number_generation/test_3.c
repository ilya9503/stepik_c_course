#include <stdio.h>
#include <stdlib.h>
#define RAND_MAX 32767

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    // здесь продолжайте программу
    for (int i = 0; i < 10; i++)
        printf("%.2f ", ((double)rand() / (double)RAND_MAX) * (b - a) + a);
    return 0;
}