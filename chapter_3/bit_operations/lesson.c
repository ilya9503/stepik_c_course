#include <stdio.h>

int main (void)
{
    /*
        unsigned char = 1 байт = 0..255 в десятичной форме
        153 + 102 = 255 = 11111111
    */
    unsigned char var = 153;        // двоичная запись 10011001 = 153
    unsigned char not_var = ~ var;  // двоичная запись 01100110 = 102

    printf("var = %d, not_var = %d\n", var, not_var);
    
    return 0;

}