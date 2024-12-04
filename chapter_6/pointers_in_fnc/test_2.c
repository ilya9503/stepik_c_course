#include <stdio.h>
#define NUM 20

int prod_ar(const int* ar, int length)
{
    int res = 1;
    for(int i = 0; i < length; ++i)
        res *= ar[i];
    return res;
}

int main(void)
{
    // здесь продолжайте функцию main
    int ar[NUM] = {0};
    int count = 0;
    while(scanf("%d ", &ar[count]) == 1 && count < NUM)
        count++;
        
    printf("%d", prod_ar(ar, count));

    return 0;
}