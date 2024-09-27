#include <stdio.h>

int main(void)
{
/*
    int a, b;
    scanf("%d %d", &a, &b);
    a *= 3;
    b -= 10;
    printf("%d", a * b);

    double a, b;
    scanf("%lf %lf", &a, &b);

    printf("Периметр: %.1f", (a + b) * 2.0);

    int s, m;

    scanf("%d %d", &s, &m);
    double s_d = (double)s;
    double m_d = (double)m;
    printf("%.2f", (s_d - (s_d * m_d / 100.0)) * 2.0);
*/

    int u;
    scanf("%d", &u);
    double u_ms = (double)u;
    double u_kmh = (u_ms * 3600.0) / 1000.0;
    printf("%.1f", u_kmh);
    unsigned long long a = 3;

    return 0;
}