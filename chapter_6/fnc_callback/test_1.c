#include <stdio.h>
#include <string.h>

void copy_string(char* dst, size_t max_len_dst, const char* src, int(*filter)(const char))
{
    // здесь продолжайте функцию
    const char *ptr = src;
    for (int i = 0, j = 0; j < max_len_dst; i++) {
        if(filter(src[i])) {
            strncat(dst, ptr, 1);
            ++j;
        }
        ++ptr;
    }
}

int filter_symbols(const char ch)
{
    // ASCII: 65-90 A-Z, 97-122 a-z
    if(ch <= 90 && ch >= 65 || ch <= 122 && ch >= 97)
        return 0;
    else
        return 1;
}

int main(void)
{
    char str[100] = {0}, str2[20] = {0};
    
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';
    
    // здесь продолжайте программу
    copy_string(str2, sizeof(str2)/sizeof(*str2), str, filter_symbols);
    printf("%s", str2);
    //puts(str2);
    //printf("%d", filter_symbols(str[0]));

    return 0;
}