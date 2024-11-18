#include <stdio.h>
#include <string.h> /* srtcpy(), strncpy() */

int main(void)
{
    char source[100] = "Source string";
    char destination[20];

    /*   Способ №1 как скопировать строку из одного массива в другой вручную   */

    const char *src = source;
    char *dst = destination;
    int max_len_copy = sizeof(destination);

    while (*src != '\0' && max_len_copy-- > 1)
        *dst++ = *src++;
    
    puts(destination);

    /*   Способ №2. Используем функцию strcpy()  */ 
    strcpy(destination, source);
    puts(destination);

    /*   Способ №3. Используем функцию strncpy(), доп аргумент с максимальным числом символов в получателе  */
    int max_len = sizeof(destination) - 1;

    strncpy(destination, source, max_len);
    destination[max_len] = '\0';  // учтем завершающий нуль для формирования корректной Си-строки 
    puts(destination);

    return 0;
}