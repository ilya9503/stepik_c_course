#include <stdio.h>

double ar_d[20] = {0.0};

int main(void)
{
    double summ = 0;
    int n = sizeof(ar_d) / sizeof(*ar_d);
    int i = 0;
//    printf("%d", n);
    for ( ; i < n && scanf("%lf ", &ar_d[i]) == 1; ++i) {
        summ += *(ar_d + i);
    }

    summ /= (double)i;
    printf("%.2f", summ);
    return 0;
}
