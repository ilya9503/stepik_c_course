#include <stdio.h>
#include <math.h>

int main(void)
{
    double grad;
    if (scanf("%lf", &grad) != 1) {
        printf("Input error\n");
        return 0;
    }

    double rad = grad * 3.1415 / 180;
    printf("%.1f", sin(rad));

    return 0;
}
