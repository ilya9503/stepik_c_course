/*
    Сделать пирамидку из звездочек
*/
#include <stdio.h>

int main(void)
{
    int n;          // считывается из входного потока
    int stars = 1;  // начальное кол-во звезд

    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Incorrect input!");
        return 0;
    }

    int spaces = n - 1;             // начальное кол-во пробелов
    
    for(int i = 1; i <= n; ++i) {   // количество строк

        for(int j = 1; j <= spaces; ++j) {  // кол-во пробелов
            printf(" ");
        }
        
        for (int k = 1; k <= stars; ++k) {  // кол-во звезд, арифметическая прогрессия
            printf("*");
        }

        stars += 2;
        --spaces;
        printf("\n");
    }    

    return 0;
}