#include <stdio.h>

int main(void)
{
    FILE* fp = fopen("test.dat", "r");
    if(fp == NULL)
        return 2;
    fclose(fp);

    return 0;
}