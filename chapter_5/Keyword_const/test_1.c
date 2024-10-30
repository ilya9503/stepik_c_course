#include <stdio.h>

int main(void)
{
    int* ptr;
    const int* ptr_cnst;    // данные
    int * const cnst_ptr;   // указатель

    ptr = ptr_cnst;

    ptr = cnst_ptr;

    --ptr_cnst;

//    cnst_ptr = ptr;

//    cnst_ptr++;

    *cnst_ptr = 77;

//    ptr_cnst = ptr;

//    *ptr_cnst = 10;

long const lg = 10;



    return 0;
}