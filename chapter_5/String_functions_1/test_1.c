/*
    Продолжите программу. В строке str необходимо найти последний символ '\n' и если он найден,
    то заменить на символ '\0'. Вывести в консоль полученную строку str в квадратных скобках.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = {"Языки Си. Строки\n"};
//    fgets(str, sizeof(str)-1, stdin);

    // здесь продолжайте программу

    // Заменяем \n на \0 для fgets()
    char *ptr = strchr(str, '\n');
    if(ptr != NULL)
        *ptr = '\0';

    printf("[%s]", str);
/*
    // Добавляем []
    char buf[100] = {0};

    buf[0] = '[';
    strcat(buf, str);
    buf[strlen(buf)] = ']';
    buf[strlen(buf)] = '\0';
    strcpy(str, buf);  
    printf("%s", str);
*/
    return 0;
}