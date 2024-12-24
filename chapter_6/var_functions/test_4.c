#include <stdio.h>
#include <stdarg.h>
#define SIZE    5

void ar_fill(double ar[], size_t num, ...)
{
    va_list arg;
    va_start(arg, num);
    for (int i = 0; i < num; ++i)
        ar[i] = va_arg(arg, double);
    va_end(arg);  
}

int main(void)
{
    double weights[SIZE] = {0};
    ar_fill(weights, SIZE, 0.1, 0.2, 0.3, 0.4, 0.5);
    for (int i = 0; i < SIZE; i++)
        printf("%.1f ", weights[i]);
    return 0;
}