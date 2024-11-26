/*
    Решено методом удаления ячейки из массива (простой способ)
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '-' && str[i+1] == '-') {
            for (int j = i; str[j] != '\0'; ++j)
                str[j] = str[j+1];
            --i;
        }
    }

    puts(str);

    return 0;
}