#include <stdio.h>

// здесь объявляйте макро-функцию
#define GET_MAX(A, B) (((A) > (B)) ? (A) : (B))

int main(void)
{
    double val_1, val_2;
    if(scanf("%lf; %lf", &val_1, &val_2) != 2) {
        printf("Input error");
        return 0;
    }

    // здесь продолжайте программу
    double res = GET_MAX(val_1+1, val_2-1) / (val_1 + val_2);
    printf("%.2f", res);


    return 0;
}