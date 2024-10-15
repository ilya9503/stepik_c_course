#include <stdio.h>

int main(void)
{
    int n;
    int s = 1;

    do {
        scanf("%d", &n);
        if(n <= 0)
            continue;
        s *= n;
    } while (n != 0);

    printf("%d", s);
    
    return 0;
}