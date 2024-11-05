#include <stdio.h>

#define TOTAL     10

int main(void)
{
    int digs[TOTAL] = {0};
    size_t count = 0;
    size_t sz_ar = sizeof(digs) / sizeof(*digs);

    while(count < sz_ar && scanf("%d", &digs[count]) == 1)
        count++;
    // здесь продолжайте программу
    int ins_num = -1;
    // Перебираем массив digs
    for (int i = 0; i < count; ++i) {
        if(digs[i] == 5) {
            for(int j = count; j > i; --j) {
                digs[j] = digs[j-1];
            }
            digs[i+1] = ins_num;
            ++count;
            ins_num += -1;
        }
    }

    for (int i = 0; i < count && i < 10; ++i) {
        printf("%d ", digs[i]);
    }

    return 0;
}