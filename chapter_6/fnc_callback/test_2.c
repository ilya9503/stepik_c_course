#include <stdio.h>
#define NUM     20

int sum_ar(const int *ar, size_t len_ar, int(*check)(int))
{
    int sum = 0;
    for(int i = 0; i < len_ar ;++i)
        if(check(ar[i]))
            sum += ar[i];
    return sum;
}

int is_even(int num)
{
    if(num % 2 == 0)
        return 1;
    else
        return 0;
}

int main(void)
{
    int marks[NUM] = {0};
    int x, i = 0;
    while(scanf("%d", &x) == 1 && i < NUM) {
        // здесь продолжайте программу
        marks[i] = x;
        ++i;
    }

    printf("%d", sum_ar(marks, NUM, is_even));

    return 0;
}