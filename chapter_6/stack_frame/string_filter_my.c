#include <stdio.h>
#include <string.h>

// Фильтрация строки
void strip_str(char* src, const char* filter)
{
    char res[100] = {0};                    // результирующая строка
    char* ptr_src = src;                    // указатель текущего найденного символа
    char* ptr_src_old = ptr_src;            // указатель предыдущего найденного символа
    size_t src_len = strlen(src);           // длина исходной строки
    
    ptr_src = strpbrk(ptr_src, filter);     // 1. ищем символ
    if(ptr_src != ptr_src_old) {            // 2. печатаем символы до него
        strncat(res, src, ptr_src - ptr_src_old);
    }
    ++ptr_src;                              // 3. пропускаем символ
    ptr_src_old = ptr_src;

    while(ptr_src != NULL) {
        ptr_src = strpbrk(ptr_src, filter);                     // 1. ищем следующий символ
        if(ptr_src != ptr_src_old && ptr_src != NULL) {         // 2. печатаем символы до него
            strncat(res, ptr_src_old, ptr_src - ptr_src_old);
            ++ptr_src;                                          // 3. пропускаем символ
            ptr_src_old = ptr_src;
        }      
    }
    strncpy(src, res, src_len);
}

int main(void)
{
    char str[100] = {0}, str2[20];
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';
    // здесь продолжайте функцию main
    strcpy(str2, ".,-!?");     // фильтр
    strip_str(str, str2);
    printf("%s", str);
    return 0;
}