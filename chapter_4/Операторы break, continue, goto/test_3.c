#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    for(int i = 1; i < n; ++i) {
        if (i*i >= n)
            break;
        printf("%d ", i);
    }


    return 0;
}