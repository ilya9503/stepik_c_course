#include <stdio.h>
#include <string.h> /* srtcpy(), strncpy(), strlen() */

int main(void)
{
    char str[100] = "Length of the string";

    /*   Способ №1. Ручной расчет длины строки   */
    const char *buf = str;
    size_t length = 0;

    // TRUE пока следующий символ НЕ нуль (завершающий нуль строки)
    while(*buf++)
        length++;

    printf("length = %zu\n", length);

    /*   Способ №2. Используя strlen()   */
    size_t length_1 = strlen(str);
           

    return 0;
}