/*
    Продолжите программу. В переменной str содержится E-mail адрес.
    Необходимо проверить его корректность. Для этого в str должен присутствовать один символ '@'
    (не первый), а после него (не сразу) - символ '.' (не последний).
    Также в самом E-mail адресе допустимы только символы: a-z, A-Z, 0-9, '.', '_', '-'.
    Если строка str содержит корректный E-mail адрес, то в консоль вывести 1, иначе 0.
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

    // здесь продолжайте программу
    
    // Проверка на наличие хотя бы 1 символа @
    if(strpbrk(str, "@") == NULL || str[0] == '@') {
        printf("0");
        return 0;
    }

    // Проверка на наличие "@." и ".@"
    if(strstr(str, "@.") != NULL || strstr(str, ".@") != NULL) {
        printf("0");
        return 0;
    }

    // Проверка на наличие хотя бы одной точки после @
    char *ptr_sub;
    ptr_sub = strpbrk(str, "@");
    ptr_sub++;
    if(strstr(ptr_sub, ".") == NULL) {
        printf("0");
        return 0;
    }

    // Проверка на допустимые символы
    char buf[100] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,-.0123456789_@";
    char flag = 0;
    for (int i = 0; i < strlen(str); ++i) {
        flag = 0;
        for(int j = 0; j < strlen(buf); ++j) {
            if(str[i] == buf[j])
                flag = 1;
        }
        if(!flag) {
            printf("0");
            return 0;            
        }
    }

    /* Пример более краткого решения
            for(char i = 0; i < strlen(str); ++i) {
                    if(strchr(buf, str[i]))
                        continue;
                    res = 0;
    }
    */
    
    printf("1");

    return 0;
}