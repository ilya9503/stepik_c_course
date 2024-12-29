#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_ln(char* buffer, size_t max_len)
{
    fgets(buffer, max_len-1, stdin);
    char* ptr_n = strrchr(buffer, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';
}

// здесь объявляйте функцию
char * merge_string(const char* str1, const char* str2)
{
    size_t len_1 = strlen(str1);            // длина 1 строки
    size_t len_2 = strlen(str2);            // длина 2 строки
    size_t len_new = len_1 + len_2 + 1;     // длина результирующей строки с учетом \0
    char *new_str = calloc(len_new, sizeof(char));
    memcpy(new_str, str1, sizeof(char) * len_1);
    new_str += len_1;
    memcpy(new_str, str2, sizeof(char) * len_2);
    new_str += len_2;
    strcat(new_str, "\0");
    new_str -= len_new-1;
    return new_str;
}


int main(void)
{
    char str_1[200] = {0};
    char str_2[200] = {0};

    get_ln(str_1, sizeof(str_1));
    get_ln(str_2, sizeof(str_2));

    // здесь продолжайте функцию main
    char *res_str = merge_string(str_1, str_2);
    printf("%s", res_str);
    free(res_str);

    return 0;
}