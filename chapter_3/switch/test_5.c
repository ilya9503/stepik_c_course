#include <stdio.h>

int main(void)
{
    int num;

    if(scanf("%d", &num) != 1) {
        printf("Input error.");
        return 0;
    }

    if ((num / 1000) == 3)
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}