#include <stdio.h>
#include <string.h>

int define_char(const char ch)
{
    if(ch >= '0' && ch <= '9')
        return 1;   // number
    else
        return 0;   // other
}

int match_ab(const char a, const char b)
{
    if(define_char(a) && !define_char(b))
        return 1;
    if(!define_char(a) && define_char(b))
        return 0;
    return a < b;
}

void sort_string(char *str, size_t max_len, int(*compare)(const char, const char))
{
    // здесь продолжайте функцию
    for(int i = 0; i < max_len-1; ++i) {
        int pos = i;
        // 1. Ищем максимальный индекс
        for(int j = i; j < max_len; ++j)
            if(!match_ab(str[pos], str[j]))
                pos = j;
        // 2. Если индекс отличается, от текущего, меняем их местами
        if (pos != i) {
            char ch = str[i];
            str[i] = str[pos];
            str[pos] = ch;
        }
    }
}

int main(void)
{
    char str[100] = {0};
    
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';
    
    // здесь продолжайте программу
    size_t max_len = strlen(str);
//    printf("%s\n", str);
    sort_string(str, max_len, match_ab);
    printf("%s", str);

    return 0;
}