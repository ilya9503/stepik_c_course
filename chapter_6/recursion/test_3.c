#include <stdio.h>
#define MAX_LENGTH    20

int sum_ar(const short* ar, size_t len, size_t indx)
{   
    if(indx == len)
        return 0;
    return ar[indx] + sum_ar(ar, len, indx + 1);
}

int main(void)
{
    short ar[MAX_LENGTH];
    int count = 0;
    while(count < MAX_LENGTH && scanf("%hd", &ar[count]) != EOF)
        count++;

    printf("%d", sum_ar(ar, count, 0));

    return 0;
}