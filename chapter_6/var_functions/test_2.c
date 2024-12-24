#include <stdio.h>
#include <string.h>
#include <stdarg.h>

double v_norm2(char* str, ...);

int main(void)
{
    printf("%.1f", v_norm2("vector2", 1.0, 2.0));
    return 0;
}

double v_norm2(char* str, ...)
{

    va_list arg;                // указатель на параметр
    va_start(arg, str);         // получение адреса первого вариадического параметра
    int coords = 0;
    double res = 0.0;

    if(!strcmp(str, "vector2"))
        coords = 2;
    else if(!strcmp(str, "vector3"))
        coords = 3;
    else if(!strcmp(str, "vector4"))
        coords = 4;
    else
        return 0.0;

    for (int i = 0; i < coords; i++) {
        double par = va_arg(arg, double);
        res += par * par;
    }
    va_end(arg);
    return res;    
}