#include <stdio.h>

int main(void)
{
    int m, n;
    int s = 0;
    scanf("%d %d", &n, &m);

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m ; ++j) {
            if((i+j) < 10)
                s += i + j;
            else
                break;
//                goto mark1;
        }
    }

//    mark1: printf("%d", s);
    printf("%d", s);
    
    return 0;
}