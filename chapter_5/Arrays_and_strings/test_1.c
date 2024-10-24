#include <stdio.h>
#define ARRAY_SIZE  5

int main(void)
{
    // здесь продолжайте программу
    int digits[ARRAY_SIZE];
    scanf("%d %d %d %d %d", &digits[0], &digits[1], &digits[2], &digits[3], &digits[4]);
    for (int i = 0; i < 5; i++) {
        printf("%d ", digits[i]);
    }
    
 //   __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}