#include <stdio.h>

int main(void)
{
    char data[5][10];
    int i = 0;

    while (i < 5) {
        scanf("%9s", data[i]);
        printf("[%s]\n", data[i]);
        ++i;
    }

    return 0;
}