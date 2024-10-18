#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    for( ;n <= m ; ++n){
        if(n % 2 == 0)
            printf("%d ", n);
    }
    
    return 0;
}