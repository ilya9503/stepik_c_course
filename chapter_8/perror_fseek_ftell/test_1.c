#include <stdio.h>

int main(void)
{
    char byte;
    FILE* fp = stdin; // стандартный поток для чтения данных

    // здесь продолжайте программу
    while ((byte = fgetc(fp)) != EOF) {
        printf("%d:%ld ", byte, ftell(fp));
    }
    
    //fseek(fp, -1, SEEK_END);  // предпоследний символ
    //fseek(fp, 1, SEEK_SET);   // 2-ой символ
    // fclose(fp); для стандартного потока делать не нужно

    return 0;
}