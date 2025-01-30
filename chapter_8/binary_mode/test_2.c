#include <stdio.h>

int main(void)
{
    short data[10] = {0};
    FILE* fp = stdin; // имитация входного потока

    int count = 0;
    while(count < 10 && fread(&data[count], sizeof(*data), 1, fp) == 1)
        ++count;

    for (int i = 0; i < count; ++i)
        printf("%hd ", data[i]);
    
    // fclose(fp);

    return 0;
}