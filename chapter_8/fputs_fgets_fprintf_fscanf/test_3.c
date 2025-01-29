#include <stdio.h>

enum {max_length_ar=20};

int main(void)
{
    double temp[max_length_ar];

    FILE* fp = stdin; // имитация отрытого файлового потока
    int count = 0;
    while(fscanf(fp, "%lf ", &temp[count]) == 1 && count < max_length_ar)
        ++count;

    for (int i = 0; i < count; ++i)
        if (temp[i] >= 0)
            printf("%.2f ", temp[i]);

    // fclose(fp); закрывать стандартный поток не нужно

    return 0;
}