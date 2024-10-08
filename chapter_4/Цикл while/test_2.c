#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, i = 1;
    double s = 0.0;

    if (scanf("%d", &n) != 1) {
        printf("Error input");
        return 0;
    }

    while (i <= n) {
        // pow(i, 2)
        s += 1.0 / (i * i);
        ++i;
    }

    printf("%.3f", s);

    return 0;
}