#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = {"https://proproprogs.ru/c_base/cpp-znacheniya-parametrov-funkcii-po-umolchaniyu"};
    //fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    size_t length;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '-') {
            length = strlen(str);
            for (int j = length; j > i; --j)
                str[j+2] = str[j];
            str[i+1] = '+';
            str[i+2] = '-';
            i += 2;
        }
    }

    puts(str);

    return 0;
}