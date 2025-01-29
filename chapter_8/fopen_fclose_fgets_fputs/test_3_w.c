#include <stdio.h>

int main(void)
{
    FILE* fp = fopen("test_file.txt", "w");
    if(fp == NULL)
        return 1;

    int data[] = {1, 2, 3, 0, -1, -100};
    for(int i = 0; i < sizeof(data) / sizeof(*data); ++i)
        fputc(data[i], fp); // запишет числа 1, 2, 3.. которые по ASCII не являются символами

    fclose(fp);

    return 0;
}