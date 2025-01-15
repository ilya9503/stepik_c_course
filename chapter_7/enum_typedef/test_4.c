#include <stdio.h>
#include <string.h>

typedef int (*FUNC_CORRECT)(const char*);   // указатель на функцию типа int

int is_correct(const char* str)
{
    // locate "ra", "RA", "rA", "Ra" in string
    if (strstr(str, "ra") != NULL || strstr(str, "RA") != NULL || strstr(str, "rA") != NULL || strstr(str, "Ra") != NULL)
        return 1;
    return 0;      
}

int get_correct_words(const char (*words)[50], int count_words, FUNC_CORRECT filter)
{
    count_words = 0;
    for(int i = 0; i < sizeof(words) / sizeof(words[0]); ++i)
        if(filter(words[i])) ++count_words;
    return count_words;
}



int main(void)
{
    char words[20][50];
    int count = 0, res = 0;
    FUNC_CORRECT filter = is_correct;

    for (int i = 0; i < 20; ++i) {
        scanf("%49s", words[i]);
    }
/*
    while(count < 20 && fgets(words[count], sizeof(words[count])-1, stdin)) {
        char* ptr_n = strrchr(words[count], '\n');
        if(ptr_n != NULL)
            *ptr_n = '\0';
        count++;
    }
*/
    res = get_correct_words(words, res, filter);
    printf("%d", res);

    return 0;
}