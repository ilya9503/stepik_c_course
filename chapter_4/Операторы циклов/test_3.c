#include <stdio.h>

int main(void)
{
    int n, sum = 0;

    if (scanf("%d", &n) != 1) {
        printf("Error input");
        return 0;
    }

    while (n > 0) {
        int rem;        // остаток
        rem = n % 10;
        n = n / 10;
        sum += rem; 
    }
    printf("%d", sum);

    return 0;
}