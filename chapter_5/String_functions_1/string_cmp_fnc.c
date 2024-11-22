/*  Функция сравнения 2 строк по-символьно (полностью)    */
#include <stdio.h>
#include <string.h> /*  strcmp() */

int main(void)
{
    char s1[12] = "Hello";
    char s2[10] = "Hello";

//    int res = strcmp(s1, s2);
    if (strcmp(s1, s2) == 0)
        puts("Strings are equal!");
    else
        puts("Strings are not equal!");
    
    return 0;
}