#include <iostream>
#include <cstdio>       // FILE*, stdin
#include <cstring>
#include <math.h>

struct vector4D {
    double x, y, z, t;

    // для чтения из входного потока stream данных в переменные x, y, z, t, записанных через разделитель sep
    void read_data(FILE* stream, char sep=' ') 
    {
        char temp[2] = {sep, '\0'};     // Временная строка из 1 символа
        char format_string[50] = "";    // Собираем форматную строку для fscanf()
        strcat(format_string, "%lf");
        strncat(format_string, temp, 1);
        strcat(format_string, "%lf");
        strncat(format_string, temp, 1);
        strcat(format_string, "%lf");
        strncat(format_string, temp, 1);
        strcat(format_string, "%lf");
        // int fscanf ( FILE * stream, const char * format, ... );
        fscanf(stream, format_string, &x, &y, &z, &t);
    }

    // для вычисления длины радиус вектора
    double length() { return sqrt(x*x + y*y + z*z + t*t); }
};


int main(void)
{
    // здесь продолжайте функцию main
    vector4D v1, v2;
    
    v1.read_data(stdin, ';');
    v2.read_data(stdin, ';');

    printf("%.3f %.3f", v1.length(), v2.length());
    
/*
    printf("%.2f %.2f %.2f %.2f", v1.x, v1.y, v1.z, v1.t);
    printf("\n");
    printf("%.2f %.2f %.2f %.2f", v2.x, v2.y, v2.z, v2.t);
*/
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}