#include <stdio.h>

int main(void)
{
    unsigned char bits;
    scanf("%hhu", &bits);

    // здесь продолжайте программу

    unsigned char mask = 0b00101000;   // 0010 1000 = 40

    if ((bits & mask) == mask)
        printf("%u", bits);
    else
        printf("-1");

    return 0;
}