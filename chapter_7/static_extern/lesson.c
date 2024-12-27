#include <stdio.h>

char name[] = "Variables";  /*  в секции .data  */
double big_ar[1000000];     /*  в секции .bss  */
int global_var;                      /*  внешнее связывание, глобальная переменная доступна во всех модулях */
static int global_var_1;             /*  внутреннее связывание, глобальная переменная доступна в пределах одного модуля */

int main(void)
{
    int var_main;           /*  автоматическая локальная переменная, находится в стековом фрейме */
    static int var_st;      /*  статическая локальная переменная, находится в секции .bss, вместе с глобальными    */

    printf("var_main = %d, var_st = %d\n", var_main, var_st);

    return 0;
}