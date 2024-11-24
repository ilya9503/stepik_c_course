/*
    Продолжите программу. Замените в строке str все дефисы (-) фрагментом "-+-".
    Выведите полученную строку в консоль. В тестах гарантируется, что результирующая строка умещается
    в массив str.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = "-inicializaciya-peremennyh-klyuchevye-slova-auto-i-";
//    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    // здесь продолжайте программу
    char new_str[100] = {0};
    int i = 0;                              // счетчик символов '-'
    char* ptr_str = strchr(str, '-');       // ищем позицию символа '-'
    ++i;

    strncat(new_str, str, ptr_str-str+1);   // сращиваем пустую new_str с str, до позиции '-' (включая позицию)
    strcat(new_str, "+-");                  // добавляем строку "+-"

    while (ptr_str != NULL) {
        char* ptr_old = ptr_str+1;
        ptr_str = strchr(ptr_str+1, '-');
        if(ptr_str != NULL) {
            strncat(new_str, ptr_old, ptr_str-ptr_old+1);   // сращиваем пустую new_str с str, до позиции '-' (включая позицию)
            strcat(new_str, "+-");                  // добавляем строку "+-"
            //printf("new_str = %s\n", new_str);
            //printf("ptr_old = %s, ptr_str = %s\n", ptr_old, ptr_str);
            //printf("string = %s, pos = %d\n", ptr_str, ptr_str-str+1);
            //printf("%s\n", ptr_str);
            //printf("found at %d\n",ptr_str-str+1);  // +1 из-за завершающего 0
            ++i;
        }
        else
            strncat(new_str, ptr_old, strlen(ptr_old));   // сращиваем пустую new_str с str, до позиции '-' (включая позицию)
    }
    printf("old_str = %s\n", str);
    printf("new_str = %s\n", new_str);
    printf("%d", i);

    return 0;
}