#include <stdio.h>

int main (void)
{
    /*
        unsigned char = 1 ���� = 0..255 � �����筮� �ଥ
        153 + 102 = 255 = 11111111
    */
    unsigned char var = 153;        // ����筠� ������ 10011001 = 153
    unsigned char not_var = ~ var;  // ����筠� ������ 01100110 = 102

    printf("var = %d, not_var = %d\n", var, not_var);
    
    return 0;

}