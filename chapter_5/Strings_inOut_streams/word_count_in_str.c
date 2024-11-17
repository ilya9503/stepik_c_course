/*
    Продолжите программу, которая читает из входного потока строку целиком с помощью функции fgets().
    На выходе формируется корректная Си строка.
    Вычислите количество слов в строке (слова разделяются одним или несколькими пробелами) и выведите
    в консоль полученное целое число.
    P. S. Пробелы могут быть в начале и в конце строки.
*/
#include <stdio.h>

void strip_string(char* str, int max_len)
{
    int count = 0;
    while(*str++ != '\0' && count++ < max_len);

    if(count > 1) {
        str -= 2;
        if(*str == '\n')
            *str = '\0';
    }
}

int main(void)
{
    char str[100];

    fgets(str, sizeof(str), stdin);
    strip_string(str, sizeof(str));

    // здесь продолжайте программу
    int num = sizeof(str) / sizeof(*str);
    int j = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if(str[i] != ' ' && (str[i+1] == ' ' || str[i+1] == '\0'))
            ++j;
    }

    printf("%d", j);

    return 0;
}