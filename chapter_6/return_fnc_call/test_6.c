#include <stdio.h>

double get_qm(double qm_1, int m, int x)
{
    return (double)(m * x * qm_1) / (double)m;
}

int main(void)
{
    int x;
    int m = 1;
    double qm, qm_1;

    while(scanf("%d", &x) == 1) {
        // здесь продолжайте программу
        qm = get_qm(qm_1, m, x);

        m++;
    }

    printf("%.3f", qm);

    return 0;
}