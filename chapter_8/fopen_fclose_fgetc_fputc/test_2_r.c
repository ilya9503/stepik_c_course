#include <stdio.h>

int main(void)
{
    FILE* fp = fopen("test_file.txt", "r");
    if(fp == NULL)
        return 1;

    int data;
    while((data = fgetc(fp)) != EOF)
        printf("%c ", data);

    fclose(fp);

    return 0;
}