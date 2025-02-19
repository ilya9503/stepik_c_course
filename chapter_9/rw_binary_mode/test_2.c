#include <stdio.h>

int main(void)
{
    int n = 7;
    while(n-- > 0) {
        int n = 5;
        printf("%d\n", n);
        n++;
    }
    
    printf("%d\n", n);

    return 0;
}