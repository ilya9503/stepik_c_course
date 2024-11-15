#include <stdio.h>

int main(void)
{
    char data[6][20];
    int i = 0;
    int num = sizeof(data) / sizeof(data[0]);

    while (i < num) {
        scanf("%19s", data[i]);
        ++i;
    }

    for (int i = num-1; i >= 0 ; --i) {
        printf("%s ", data[i]);
    }
    
    return 0;
}