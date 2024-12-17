#include <stdio.h>
#define MAX_SIZE    20

void swap(short *val1, short *val2)
{
    int temp = *val2;
    *val2 = *val1;
    *val1 = temp;
}

void reverse(short ar[], int length)
{
    int end_index = length - 1;
    for(int i = 0; i < length / 2; ++i) {
        swap(&ar[i], &ar[end_index]);
        --end_index;
    }
}

int main(void)
{
    short digs[MAX_SIZE];
    int count = 0;
    while(count < MAX_SIZE && scanf("%hd", &digs[count]) == 1)
        count++;

    // здесь продолжайте функцию main
    reverse(digs, count);
    for(int i = 0; i < count; ++i)
        printf("%hd ", digs[i]);

    return 0;
}