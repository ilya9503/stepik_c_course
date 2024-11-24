/*
    Продолжите программу. В строке str необходимо заменить все подряд идущие дефисы
    (например: --, ---, ---- и т.д.) на один дефис (-).
    Выведите в консоль полученную строку.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = {"cpp--znacheniya----parametrov-funkcii-po----umolchaniyu"};
 //   fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    // здесь продолжайте программу
    char new_str[100] = {0};
    char* ptr_str = strstr(str, "--");          // ищем позицию строки "--"

    if (ptr_str != NULL) {
        strncat (new_str, str, ptr_str - str);
        strcat (new_str, "-");                  // заменяем на "-"

    }
    
///*
    while(ptr_str != NULL) {
        char* ptr_old = ptr_str+2;
        ptr_str = strstr(ptr_str+2, "--");
        if(ptr_str != NULL) {
            strncat(new_str, ptr_old, ptr_str-ptr_old);   // сращиваем пустую new_str с str, до позиции '-' (включая позицию)
            strcat(new_str, "-");                  // добавляем строку "+-"
            --ptr_str;
        }
        //else
        //    strncat(new_str, ptr_old, strlen(ptr_old));   // сращиваем пустую new_str с str, до позиции '-' (включая позицию)        
    }
//*/
    printf("%s", new_str);

    return 0;
}