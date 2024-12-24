#include <stdio.h>
#include <stdarg.h>

double sumf(const char* format, ...)
{
    va_list arg;
    va_start(arg, format);
    double res = 0;
    const char * ptr = format;
    while (*ptr != '\0') {
        if(*ptr == '+')
            res += va_arg(arg, double);
        else
            va_arg(arg, double);
        ++ptr;  // сдвигаем указатель на 1-ый символ строки
    }
    va_end(arg);
    return res;
}

int main(void)
{
    double res = sumf("++ + +", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    //double res = sumf("++ + +", 1, 2, 3, 4, 5, 6);
    printf("%.2f ", res);

    return 0;
}