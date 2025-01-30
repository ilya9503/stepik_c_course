#include <stdio.h>
#include <string.h>

enum {max_lines=10, max_string_len=200};

int main(void)
{
    char text[max_lines][max_string_len];

    FILE* fp = stdin; // имитация отрытого файлового потока

    int count = 0;
    while(count < max_lines && fgets(text[count], max_string_len, fp)) {
        // Находим символ переноса строки
        char* ptr = strchr(text[count], '\n');
        if(ptr != NULL)
            *ptr = '\0';    // заменяем на завершающий нуль
        // Выводим строку на экран
        //puts(text[count]);
        ++count;
    }
    
    for (int i = 0; i < count; ++i)
        puts(text[i]);
    
    // fclose(fp); закрывать стандартный поток не нужно

    return 0;
}