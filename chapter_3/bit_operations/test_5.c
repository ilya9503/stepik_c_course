#include <stdio.h>

int main(void)
{
    unsigned int num1, num2;
    scanf("%u %u", &num1, &num2);

    printf("%u", (num1 >> 1) * (num2 >> 1));

    return 0;
}