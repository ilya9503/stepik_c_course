#include <stdio.h>
#define NUM 10

int sum_ar(const int* ar, int length)
{
    int res = 0;
    for(int i = 0; i < length; ++i)
        res += ar[i];
    return res;
}

int main(void)
{
    // здесь продолжайте функцию main
    int ar[NUM] = {0};
    for(int i = 0; i < NUM && scanf("%d ", &ar[i]) == 1; ++i) ;
    int res = sum_ar(ar, NUM);
    printf("%d", res);

/*
    for(int i = 0; i < NUM; ++i)
        printf("%d ", ar[i]);
*/
    return 0;
}