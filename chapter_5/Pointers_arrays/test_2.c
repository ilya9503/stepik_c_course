#include <stdio.h>

int main(void)
{
    // здесь продолжайте программу
    int value;
    scanf("%d", &value);

    char ar_d[sizeof(int)];
    int *ptr_value = &value;
    char *ptr_char = (char*)ptr_value;
/*
    char *ptr_ar_d = ar_d;
    ptr_ar_d = (char*)ptr_value;

    for (int i = 0; i < sizeof(value); ++i) {
        printf("%d ", *(ptr_ar_d + i));
    }
*/

    for (int i = 0; i < sizeof(value); ++i) {
        *(ar_d + i) = *ptr_char;
        ++ptr_char;
        printf("%d ", *(ar_d + i));
    }
  
    


//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}