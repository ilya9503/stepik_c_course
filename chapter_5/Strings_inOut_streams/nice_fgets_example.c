/*
    Продолжите программу, которая читает из входного потока строку целиком с помощью функции fgets().
    На выходе формируется корректная Си строка. Удалите из прочитанной строки все латинские символы 'e'
    и выведите в консоль полученную строку.
*/
#include <stdio.h>

void strip_string(char* str, int max_len)   // Находим в строке \n и заменяем на \0
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

    for (int i = 0; i < num; ++i) {
        if(str[i] == 'e') {
            for (int j = i; j < num-1; ++j) {
                str[j] = str[j+1];
            }
        --i;
        }
    }
    
    printf("%s", str);
    

    return 0;
}