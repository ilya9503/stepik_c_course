#include <stdio.h>

int is_positive(int x)  // проверка на натуральность
{
    return x >= 0;
}

int main(void)
{
    int n;
    if(scanf("%d", &n) != 1) {
        printf("Input error!");
        return 1;
    }

    if (! is_positive(n)) {
        printf("Incorrect Input!");
        return 2;
    }

    int stars = 1;          // звезды, начальное зн-е
    int spaces = n - 1;     // пробелы, начальное зн-е

    for (int i = 0; i < n; ++i) {           // выводим строки

        for (int j = spaces; j > 0; --j)    // выводим пробелы
            printf(" ");

        if(is_positive(spaces))
            --spaces;

        if (i > 0)
            stars += 2;                     // арифметическая прогрессия звездочек

        for (int j = 0; j < stars; ++j)
            printf("*");

        printf("\n");
    }
    
    return 0;
}