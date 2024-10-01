#include <stdio.h>

#define KMH (double)s_mc * 3600/1000 // здесь формула перевода в км/ч

int main(void)
{
    int s_mc;
    scanf("%d", &s_mc);

    // здесь продолжайте программу
    double s_kmh = KMH;
    printf("%.2f", s_kmh);

    return 0;
}