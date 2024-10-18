/*
    Указатель должен быть инициализирован на определенную область памяти
    Константа NULL в языке Си определена:
        #define NULL      ((void *)0)

    The Null Pointer is the pointer that does not point to any location but NULL.
    According to C11 standard:
    “An integer constant expression with the value 0, or such an expression cast to type void *,
        is called a null pointer constant. If a null pointer constant is converted to a pointer type,
        the resulting pointer, called a null pointer, is guaranteed to compare unequal
        to a pointer to any object or function.”
    
    Преобразование одного типа данных в другой (приведение типов):
    Type casting, or type conversion, is a fundamental concept in programming that involves converting
        one data type into another.
    This process is crucial for ensuring compatibility and flexibility within a program.



*/
#include <stdio.h>

int main(void)
{
    int arg = 5;
    int *test = NULL;


    if(test != NULL)
        *test = 1;

    return 0;
}