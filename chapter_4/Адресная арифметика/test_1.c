#include <stdio.h>

int main(void)
{
    short* p = (short *)10;     // тип short 16 бит = 2 байта
    printf("%u %p\n", p, p);    // %p адрес указателя в hex, %u unsigned int
    p++;
    printf("%u %p\n", p, p);

    double digs[100];
    double* p1 = &digs[2], *p2 = &digs[7];
    int count = p2 - p1;        // 5 блоков типа double. 5 * 8 = 40 байт (ячеек)
    printf("%d\n", count);
    printf("%d\n", sizeof(double));


    return 0;
}