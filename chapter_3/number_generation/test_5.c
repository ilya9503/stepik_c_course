#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned short N;
    scanf("%hu", &N);

    // здесь продолжайте программу
    // Задача 1
    int teabags_q = 100;
    int days = 7;
/*
    double days_per_pack = 100.0 / (double)N;
    double packs = 7.0 / (100.0 / (double)N);
*/
    printf("%d\n", (int)ceil(7.0 / (100.0 / (double)N)));

    // Задача 2
    double res = round((double)N * 2.54);
    printf("%.f", res);

    return 0;
}