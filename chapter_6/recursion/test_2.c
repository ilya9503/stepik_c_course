#include <stdio.h>
#define MAX_LENGTH    20

size_t range_to_ar(int* ptr_a, size_t max_len, int from, int to, size_t count)
{
    if(from <= to && count < max_len) {
        ptr_a[count] = from;
        range_to_ar(ptr_a, max_len, ++from, to, ++count);
    }
    if (to > max_len)
        return max_len;
    if (count == to)
        return count;
/*
    // Решение с циклом
    for(int i = 0; i < max_len; ++i) {
        if(from <= to) {
            ptr_a[i] = from;
            ++count;
        }
        ++from;
    }
    return count;
*/
}

int main(void)
{
    int max_rec;
    int ar[MAX_LENGTH];
    scanf("%d", &max_rec);

    size_t cnt = range_to_ar(ar, MAX_LENGTH, 1, max_rec, 0);

    // здесь продолжайте программу
    for (int i = 0; i < cnt; i++){
        printf("%d ", ar[i]);
    }
//    printf(" cnt = %d", cnt);
    
    return 0;
}