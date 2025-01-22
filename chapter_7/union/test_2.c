#include <stdio.h>

typedef enum {param_int=1, param_double=2} TYPE_PARAM;

typedef union {
    int data_i;
    double data_d;
} DATA;

DATA get_rect_sq(DATA a, DATA b, TYPE_PARAM type_params)
{
    return (type_params == param_int) ? (DATA){.data_i = a.data_i * b.data_i} :
                                        (DATA){.data_d = a.data_d * b.data_d};
}

int main(void)
{
    DATA sq_int = get_rect_sq((DATA){.data_i=10}, (DATA){.data_i=10}, param_int);
    DATA sq_double = get_rect_sq((DATA){.data_d=0.5}, (DATA){.data_d=1.5}, param_double);

    printf("rect_sq = %d\n", sq_int.data_i);
    printf("rect_sq = %f\n", sq_double.data_d);
   
    return 0;
}