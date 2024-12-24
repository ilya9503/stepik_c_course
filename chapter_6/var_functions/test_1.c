#include <stdio.h>
#include <stdarg.h>

double mean(int total, ...);

int main(void)
{
    double res = mean(7, 5, -10, 11, 0, 12, 4, 2);
    printf("%.2f", res);
    return 0;
}

double mean(int total, ...)
{
    int s = 0;
    int count = 0;
    va_list arg;                // указатель на параметр
    va_start(arg, total);       // получение адреса первого вариадического параметра 
    for(; count < total; ++count) {
        s += va_arg(arg, int);  // получение значение вариадического параметра
                                // и переход к следующему параметру
    }
    va_end(arg);                // завершение процедуры перебора вариадических параметров
    return (double)s / (double)count;    
}