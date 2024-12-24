#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE    20

/*
    Вход:   строка типа "csv: 0.56; -65.43; 0.1; 11.0"
    Выход:  0.56 -65.43 0.10 11.00
*/
int get_data_csv(double ar[], size_t count, const char* str)
{
    int i = 0;
    const char* ptr = str;
    while (ptr != NULL && i < count) {
        ptr = strpbrk(ptr, ":;");
        if(ptr != NULL) {
            ++ptr;
            ar[i] = atof(ptr);
            ++i;
        }
    }
    return i;
}

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    // здесь продолжайте функцию main
    double ar[SIZE] = {0.0};
    size_t len = sizeof(ar) / sizeof(*ar);
    int count = 0;
    count = get_data_csv(ar, len, str);

    for(int i = 0; i < count; ++i) {
        if(i < count-1)
            printf("%.2f ", ar[i]);
        else
            printf("%.2f", ar[i]);
    }

    return 0;
}