#include <stdio.h>

#define MAX_BUFF_SIZE   1024


int main(void)
{
    int buff_size;
    if (scanf("%d", &buff_size) != 1) {
        printf("Input error!");
        return 0;
    }

    printf("%d", buff_size > MAX_BUFF_SIZE ? buff_size = MAX_BUFF_SIZE : buff_size);

    return 0;
}