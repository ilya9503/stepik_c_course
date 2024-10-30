#include <stdio.h>

int main(void)
{
    int ar[100];
    int * const ptr_ar = ar;

    // здесь продолжайте программу
    int n = 0, i = 0;
    do {
        scanf("%d", &n);
        if(n == 78) break;
        ptr_ar[i] = n;
        ++i;
    } while (n != 78);

    for (int j = 0; j < i; ++j) {
        printf("%d ", ar[j]);
    }
    
    return 0;
}