#include <stdio.h>

typedef struct {
    unsigned old    : 7;
    unsigned salary : 20;
    unsigned height : 8;
    unsigned weight : 7;
    // 7 + 20 + 8 + 7 = 42 бита = 5 байт + 2 бита = 8 байт если округлять до int
} PERSON_DATA;

int main(void)
{
    PERSON_DATA pd = {.old = 45, .salary = 876043, .height = 186, .weight = 83};
    printf("%d", sizeof(pd));
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}