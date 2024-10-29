#include <stdio.h>

int main(void)
{
    int ar[10] = {0};
    int n = sizeof(ar) / sizeof(*ar);

    for ( int i = 0; i < n; ++i) {
        scanf("%d ", &ar[i]);
    }

    for (int i = 0; i < n; ++i) {
        if(ar[i] % 2 != 0 && ar[i] >= 0) {
            printf("1");
            return 0;           
        }
    }

    printf("0");

    return 0;
}