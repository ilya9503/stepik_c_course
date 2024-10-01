#include <stdio.h>
/*
    Текстовый препроцессор - преобразует текст программы до ее компиляции
    #define <макроимя> [тело макроса] - директива программы, макроопределение
    Испозьзуется для замены/определения констант, для лучшего восприятия программистом
*/

#define FIVE        5
#define TEN         2 * FIVE
#undef  TEN
#define TEN         10
#define TEXT        "Text message in one line"
#define TEXT2       "Text message in \
one line"
#define PRINT_D     printf("digit = %d\n", digit)
#define FORMAT      "digit = %d\n"
#define other_lesson 5

int main(void)
{
    int digit = FIVE;
    PRINT_D;

    digit = TEN;
    printf(FORMAT, digit);
    printf(TEXT "\n");
    printf(TEXT2 "\n");

    return 0;
}