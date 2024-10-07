#include <stdio.h>

int main(void)
{
    int n = 100, m = 999;

    while (n <= m) {
        if(n % 47 == 6 || n % 53 == 45)
            printf("%d ", n);
        ++n;
    }
    
    return 0;
}