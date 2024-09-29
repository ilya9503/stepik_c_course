#include <stdio.h>

int main(void)
{
    unsigned int num;
    scanf("%u", &num);

    printf("%u", num << 3);

    return 0;
}