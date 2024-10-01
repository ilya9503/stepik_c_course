#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    // здесь продолжайте программу
    int y1 = rand() % (b - a + 1) + a;
    int y2 = rand() % (b - a + 1) + a;
    int y3 = rand() % (b - a + 1) + a;
    int y4 = rand() % (b - a + 1) + a;
    int y5 = rand() % (b - a + 1) + a;
    int y6 = rand() % (b - a + 1) + a;
    int y7 = rand() % (b - a + 1) + a;
    int y8 = rand() % (b - a + 1) + a;
    int y9 = rand() % (b - a + 1) + a;
    int y10 = rand() % (b - a + 1) + a;
    printf("%d %d %d %d %d %d %d %d %d %d", y1, y2, y3, y4, y5, y6, y7, y8, y9, y10);

    return 0;
}