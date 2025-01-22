#include <stdio.h>
#define NUM 5

typedef enum {
    param_int=1, param_double=2
} TYPE_PARAM;

typedef union {
    int data_i;
    double data_d;
} DATA;

DATA sum_ar(DATA ar[], size_t len, TYPE_PARAM type)
{
    DATA sum = {.data_d = 0.0};
    if(type == param_int) {
        for (size_t i = 0; i < len; ++i)
            sum.data_i += ar[i].data_i;
    }
    else {
        for (size_t i = 0; i < len; ++i)
            sum.data_d += ar[i].data_d;
    }
    return sum;    
}


int main(void)
{
    DATA res_1 = sum_ar((DATA[]){[0].data_i = 1, [1].data_i = 2, [2].data_i = 3, [3].data_i = 4, [4].data_i = 5}, NUM, param_int);
    DATA res_2 = sum_ar((DATA[]){[0].data_d = 1, [1].data_d = 2, [2].data_d = 3, [3].data_d = 4, [4].data_d = 5}, NUM, param_double);

    return 0;
}