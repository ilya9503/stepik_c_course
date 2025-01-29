#include <stdio.h>

int main(void)
{
    char buff[512];
    int w, h;

    FILE* fp = stdout; // имитация отрытого файлового потока

    if(scanf("%d %d", &w, &h) != 2) {
        printf("Input error!");
        return 1;
    }

    sprintf(buff, "rectangle: %d; %d", w, h);

    fputs(buff, fp);

    // fclose(fp); закрывать стандартный поток не нужно

    return 0;
}