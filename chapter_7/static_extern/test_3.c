#include <stdio.h>

int range(void)
{
    static int n;
    if(n == 0) {
        n = 5;
        return n;
    }
    n += 3;
    return n;
}

int main(void)
{
    printf("%d ", range());
    printf("%d ", range());
    printf("%d ", range());
    printf("%d ", range());
    printf("%d ", range());
    printf("%d ", range());
    printf("%d ", range());
    return 0;
}