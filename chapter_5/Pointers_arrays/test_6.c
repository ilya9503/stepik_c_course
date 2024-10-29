// Пример решения задачи
#include <stdio.h>

int main(void)
{
    short var_1;
    int var_2;
    long long var_3;

    scanf("%hd, %d, %ld", &var_1, &var_2, &var_3);

    unsigned char *ptr = (unsigned char *)&var_1;
    for (int i = 0; i < sizeof(short); i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }

    ptr = (unsigned char *)&var_2;
    for (int i = 0; i < sizeof(int); i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }
    
    ptr = (unsigned char *)&var_3;
    for (int i = 0; i < sizeof(long long); i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }
    return 0;
}