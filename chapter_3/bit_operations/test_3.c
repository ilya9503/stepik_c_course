#include <stdio.h>

int main(void)
{
    unsigned char bits;
    scanf("%hhu", &bits);

    // здесь продолжайте программу

    unsigned char res;  // 0000 1001

    printf("%u", res = bits ^ 0b00001001);

    return 0;
}