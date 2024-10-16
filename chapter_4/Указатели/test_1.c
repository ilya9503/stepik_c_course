#include <stdio.h>

int main(void)
{
    short* ptr_var; // не инициализирован указатель
    *ptr_var = 8;
    printf("%p %d", ptr_var, *ptr_var);

    return 0;
}