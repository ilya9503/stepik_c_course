#include <stdio.h>
#include <string.h>

// Заменяем строчные буквы на заглавные
char to_uppercase(char ch)
{
    if(ch >= 'a' && ch <= 'z')
        ch -= 32;
    return ch;
}

void msg_to_morse(char* dest, char* src, char** codes, const char* symbols)
{
    char* ptr_src = src;
    while(*(ptr_src)) {
        // 1. Ищем n-ый символ из src в symbols (Заменяем прописные на заглавные при необходимости)
        char* ptr = strchr(symbols, to_uppercase(*ptr_src));
        // 2. Сопоставляем его с позицией в таблице codes
        strcat(dest, codes[ptr - symbols]);
        // 3. Добавляем пробел
        if(*(ptr_src+1))
            strcat(dest, " ");
        ++ptr_src;
    }
}

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';
    // здесь продолжайте функцию main
    // массив символов (строка)
    char symbols[] = "AJS2BKT3CLU4DMV5ENW6FOX7GPY8HQZ9IR10 ";
    // массив указателей на символы (массив строк)
    char* morse[] = {".-", ".---",	"...", "..---", "-...", "-.-", "-", 
                     "...--", "-.-.", ".-..", "..-", "....-", "-..", "--", 
                     "...-", ".....", ".", "-.", ".--", "-....", "..-.", 
                     "---", "-..-", "--...", "--.", ".--.", "-.--", 
                     "---..", "....", "--.-", "--..", "----.", "..", ".-.", 
                     ".----", "-----", "-...-"};
    char res[100] = {0};
    msg_to_morse(res, str, morse, symbols);
    printf("%s", res);

    return 0;
}