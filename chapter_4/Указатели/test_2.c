#include <stdio.h>

int main(void)
{
    double var_d = 0;
    double *ptr_var_d = &var_d;

    *ptr_var_d = -54.38;
    printf("%.2f", var_d);

    // здесь продолжайте программу

  //  __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}