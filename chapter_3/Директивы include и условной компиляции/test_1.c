#include <stdio.h>

#define PERIMETR_CALC

int main(void)
{
    int a, b;
    if(scanf("%d, %d", &a, &b) != 2) {
        printf("Input error.");
        return 0;
    }
    
#ifndef PERIMETR_CALC
    int res = a * b;
    printf("%d", res);
#else
    int res = 2 * (a + b);
    printf("%d", res);
#endif

    return 0;
}