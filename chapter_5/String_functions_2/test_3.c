/*
    Продолжите программу. В переменную str считывается строка в формате:

    csv: <число 1>; <число 2>; <число 3>; ...; <число N>

    (после точки с запятой может быть любое число пробелов от 0 и выше).

    Числа представлены вещественными значениями, а их общее количество может быть любым,
    но не менее 1 и не более 50.
    Необходимо выделить из строки все числа и сохранить их в массиве csv типа double
    в порядке записи в строке.

    P. S. В консоль ничего выводить не нужно. Строка str меняться не должна.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char str[200] = {"csv: 0.53; -2.5; 4.36; 102.0; 75.3;-4.3"};
    /*
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';
    */

    // здесь продолжайте программу
    /*csv: 0.5; 24.35; -45.36; 100.0;65.3; -44.3*/
    double csv[50] = {0.0};
    size_t num = sizeof(csv) / sizeof(*csv);
    char *ptr;

    for(int i = 0; i < num; ++i) {
        if(i == 0)
            ptr = strchr(str, ':');   // ищем начало
        else
            ptr = strchr(ptr, ';'); // ищем ;
        if(ptr != NULL) {
            csv[i] = atof(ptr+1);
            ptr++;
        }
        else
            break;  
    }

    for(int i = 0; i < num; ++i)
        printf("%.2f ", csv[i]);

    /*
        Пример краткого решения:

        double csv[50];
        char* ptr = strpbrk(str, ":;");     // указатель на один из символов, если присутствуют
        int i = 0;
        while (ptr != NULL) {
            csv[i] = atof((ptr + 1));
            ptr = strpbrk((ptr + 1), ":;");
            i++;
        }  
    */

    return 0;
}