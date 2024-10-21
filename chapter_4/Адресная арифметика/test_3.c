#include <stdio.h>

int main(void)
{
    int value;

    scanf("%d", &value);
//    printf("%d\n", value);
    int *ptr_value = &value;            // 4 байта
    short *ptr_2bytes = (short*)ptr_value;  // 2 байта
//    printf("%d\n", sizeof(short));

    for (int i = 1; i < 3; ++i) {
        *ptr_2bytes += 1;
        ptr_2bytes++;
    }


    printf("%d\n", value);
    
    
    return 0;
}