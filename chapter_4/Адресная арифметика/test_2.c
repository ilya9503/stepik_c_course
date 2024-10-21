#include <stdio.h>

int main(void)
{
    double value;

    scanf("%lf", &value);
    
    // здесь продолжайте программу
    double *ptr_value = &value;         // указатель на value типа double (1 адрес = 8 байт)
    char *ptr_char = (char *)ptr_value; // указатель на value типа char (1 адрес = 1 байт)

    // от 1 до 8 выводим содержимое каждого байта (ячейки памяти)
    for (int i = 1; i <= sizeof(double); ++i) {  
        printf("%d ", *ptr_char);
        ++ptr_char;
    }
    

    return 0;
}