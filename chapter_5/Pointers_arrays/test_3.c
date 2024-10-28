#include <stdio.h>

int main(void)
{
    int ar[10] = {0};
    int value;

    for ( int i = 0; i < sizeof(ar) / sizeof(*ar); ++i) {

        scanf("%d ", &ar[i]);

//        *(ar + i) = value;

        if((*(ar + i) >= 0) && (*(ar + i) % 2 != 0)) {
            printf("1");
            return 0;
        }

    }

    printf("0");

    return 0;
}