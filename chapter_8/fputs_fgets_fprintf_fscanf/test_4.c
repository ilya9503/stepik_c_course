#include <stdio.h>

typedef struct {
    unsigned int id;        // идентификатор
    unsigned int width;     // габариты
    unsigned int height;
    unsigned int depth;
    double weight;          // вес
} BOX;

int main(void)
{
    FILE* fp = stdout; // имитация отрытого файлового потока
    BOX var;
    if(scanf("%u; %u; %u; %u; %lf", &var.id, &var.width, &var.height, &var.depth, &var.weight) != 5) {
        printf("Input error!");
        return 1;
    }   

    fprintf(fp, "box %u: %u x %u x %u", var.id, var.width, var.height, var.depth);
    // fclose(fp); закрывать стандартный поток не нужно

    return 0;
}