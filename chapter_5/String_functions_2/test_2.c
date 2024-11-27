/*
    Продолжите программу. В переменную str считывается строка в формате:

    <наименование товара>: <высота> x <ширина> x <длина>.

    (Символ x - латинская буква.) Значения высоты, ширины и глубины представлены целыми числами.
    Необходимо выделить их из строки и сохранить в целочисленные переменные:
    h (высота), w (ширина), d (длина).

    P. S. В консоль ничего выводить не нужно. Строка str меняться не должна.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    // здесь продолжайте программу
    /*
        флэшка: 10 x 50 x 100
                h    w    d
        Пример в одну строку #1
            sscanf(str, "%*s %d %*c %d %*c %d", &h, &w, &d);
        Пример в одну строку #2
            sscanf(str, "%*[^:]:%d x %d x %d", &h, &w, &d);

    */
   
    char *ptr = strchr(str, ':');
    int h = atoi(ptr+1);

    ptr = strchr(str, 'x');
    int w = atoi(ptr+1);

    ptr = strrchr(str, 'x');
    int d = atoi(ptr+1);    
 

   printf("%d %d %d", h, w, d);



    return 0;
}