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
    char* ptr_str = strchr(str, '-');          // ищем позицию строки "--"
        if(ptr_str != NULL) {
            strncat (new_str, str, ptr_str - str);      // вставляем строку до "-"
            if(*(ptr_str+1) == '-') {
                strcat (new_str, "-");                  // добавляем "-"
                ++ptr_str;
            }      
        }

    while(ptr_str != NULL) {
        ptr_str = strchr(ptr_str+1, '-');
        if(ptr_str != NULL) {
            strncat (new_str, str, ptr_str - str);      // вставляем строку до "-"
            if(*(ptr_str+1) == '-') {
                strcat (new_str, "-");                  // добавляем "-"
                ++ptr_str;
            }      
        }
    }

/*
    while (ptr_str != NULL) {
        char* ptr_old = ptr_str;
        ptr_str = strchr(ptr_str+1, '-');
        if(ptr_str != NULL && (*(ptr_str+2) != '-')) {
            strncat(new_str, ptr_old, ptr_str-ptr_old);     // сращиваем пустую new_str с str, до позиции '-' (включая позицию)
            strcat(new_str, "-");                           // добавляем строку "+-"
        }
//        else if(ptr_str != NULL && (*(ptr_str+1) == '-'))
//            strncat(new_str, ptr_old, ptr_str-ptr_old);
 //       else
 //           strncat(new_str, ptr_old, strlen(ptr_old));


            
        //    strncat(new_str, ptr_old, strlen(ptr_old));   // сращиваем пустую new_str с str, до позиции '-' (включая позицию)
    }
*/
    printf("%s", new_str);

    return 0;
}