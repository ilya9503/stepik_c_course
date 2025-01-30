#include <stdio.h>
#include <string.h>

int main(void)
{
    char buff[512];
    char key[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    FILE* fp = stdin; // имитация отрытого файлового входного потока
    if(fgets(buff, sizeof(buff), fp) == NULL) {
        return -1;
    }

    char* ptr_buff = buff;
    int word_count = 0;
    
    while(ptr_buff != NULL) {               // сдвигаем указатель до конца строки
        ptr_buff = strpbrk(ptr_buff, key);  // ищем первый символ слова
        if(ptr_buff != NULL)
            ++word_count;
        if(ptr_buff == NULL)
            break;
        ptr_buff = strchr(ptr_buff, ' ');   // ищем первый пробел
    }

    printf("%d", word_count);
    // fclose(fp); закрывать стандартный поток не нужно

    return 0;
}