#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    // здесь продолжайте программу
    int x1 = rand() % (N + 1);
    int x2 = rand() % (N + 1);
    int x3 = rand() % (N + 1);
    int x4 = rand() % (N + 1);
    int x5 = rand() % (N + 1);
    int x6 = rand() % (N + 1);
    int x7 = rand() % (N + 1);

    printf("%d %d %d %d %d %d %d", x1, x2, x3, x4, x5, x6, x7);

    return 0;
}