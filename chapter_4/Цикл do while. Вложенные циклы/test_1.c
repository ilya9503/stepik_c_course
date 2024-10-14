#include <stdio.h>

int main(void)
{
    int p = 1, n, i = 1;
    scanf("%d", &n);

    do
    {
        p *= i;
        ++i;
    } while (i <= n);
    

/*
    for(int i = 2;i <= n; ++i)
        p *= i;
*/
    printf("%d", p);

    return 0;
}