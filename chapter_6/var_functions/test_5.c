#include <stdio.h>
#include <stdarg.h>

void ar_scan(double ar[], size_t count, ...)
{
    va_list arg;
    va_start(arg, count);
    double *var;
    for (int i = 0; i < count; ++i) {
        var = va_arg(arg, double*);
        *var = ar[i];
    }
    va_end(arg);    
}

int main(void)
{
    double weights[40] = {1.25, 4.34, -5.43, 0.01, -0.8};
    double w1, w2, w3;
    ar_scan(weights, 3, &w1, &w2, &w3);

    printf("%.2f %.2f %.2f", w1, w2, w3);

    return 0;
}