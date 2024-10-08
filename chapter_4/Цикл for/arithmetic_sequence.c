/*
    Арифметическая прогрессия
*/
#include <stdio.h>

int main(void)
{
    int a1, d, n;
    scanf("%d; %d; %d", &a1, &d, &n);

    /*
        an = a1 + (n-1)*d
            d - разность прогрессии
            a1 - первый член
            n - кол-во членов
    */

    for (int i = 0; i < n; ++i) 
        printf("%d ", a1 + d * i);
    
    return 0;
}