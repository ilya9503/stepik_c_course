#include <stdio.h>

int is_even(int x)
{
    if(x % 2 == 0)
        return 1;
    return 0;
}

int main(void)
{
    int x;
    while(scanf("%d", &x) == 1) {
        // здесь продолжайте программу
        if(is_even(x))
            printf("%d ", x);
    }

    return 0;
}