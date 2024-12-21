#include <stdio.h>
#define MAX_LENGTH 20
size_t range_to_ar(int* ptr_a, size_t max_len, int from, int to, size_t count){
    if (count < max_len && from <= to) {
        ptr_a[count] = from;
        count = range_to_ar(ptr_a, max_len, from + 1, to, count + 1);
    } return count;
}
int main(){
    int max_rec, ar[MAX_LENGTH];
//    scanf("%d", &max_rec);
    size_t cnt = range_to_ar(ar, MAX_LENGTH, 1, 5, 0);
    for (int i = 0; i < cnt; ++i) printf("%d ", ar[i]);
    return 0;
}