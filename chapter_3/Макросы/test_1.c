#include <stdio.h>
#define __ASSERT_TESTS__ \
int _a1 = GET_WIDTH(1280) == 1280; \
int _a2 = GET_WIDTH(1285 - 10) == 1275; \
assert(("Макрос GET_WIDTH(1280) вернул не верное значение", _a1)); \
assert(("Макрос GET_WIDTH(1285 - 10) вернул не верное значение", _a2));

#define MAX_WIDTH       1280
#define GET_WIDTH(W) W <= MAX_WIDTH ? W : MAX_WIDTH    // здесь продолжайте определение макро-функции

int main(void)
{
    int width;
    scanf("%d", &width);

    // здесь продолжайте программу
    // width = GET_WIDTH(width);
    printf("width = %d", width = GET_WIDTH(width));

//    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}