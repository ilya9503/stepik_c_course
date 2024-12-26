#include <stdio.h>

int main(void)
{
    int n, m;

    if(scanf("%d %d", &n, &m) != 2) {
        printf("Input error!");
        return 0;
    }

    int sum = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if((i+j) < 20)
                sum += (i+j);
            else
                goto _mark_;    // выходим из вложенного цикла
        }
    }

    _mark_: printf("%d", sum);

    return 0;
}