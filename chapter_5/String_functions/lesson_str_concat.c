#include <stdio.h>
#include <string.h> /* srtcpy(), strncpy(), strlen() */

int main(void)
{
    char str_cat[100] = "Ilya";
    char str[15] = "Savchenko";

    strcat(str_cat, str);
    printf("%s", str_cat);

    printf("\n");

    size_t max_add = sizeof(str) - strlen(str) - 1;
    strncat(str, str_cat, max_add);
    str[sizeof(str) - 1] = '\0';

    printf("%s", str);

    return 0;
}