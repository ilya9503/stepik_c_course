#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100] = {"My sister is a nervous girl, but she is very kind."};
//    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    char *ptr = str;
    int count = 0;
    while (ptr != NULL) {
        ptr = strstr(ptr, "is");
        if(ptr != NULL) {
            count++;
            ptr++;
        }
    }
      
    printf("%d", count);

    return 0;
}