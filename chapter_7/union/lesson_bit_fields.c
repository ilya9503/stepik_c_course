/*
    Битовые поля
    В языке Си есть возможность объявлять структуры с целочисленными полями типа int и дополнительно для каждого из них указывать число бит,
        которые они будут занимать в памяти устройства.
*/
#include <stdio.h>

struct date_time {
    unsigned day : 5;   // unsigned int, размер 5 бит
    unsigned month : 4;
    unsigned year : 12;
    unsigned sec : 6;
    unsigned min : 6;
    unsigned hour : 5;
    /*
        5 + 4 + 12 + 6 + 6 + 5 = 38 бит = 32 + 6 бит = 4 байта + 4 байта = 8 байт
    */
};

int main(void)
{
    struct date_time dt = {3, 5, 2023, 11, 7, 10};  // инициализация как у структур
    printf("%02d/%02d/%d %02d:%02d:%02d\n", dt.day, dt.month, dt.year, dt.hour, dt.min, dt.sec);

    return 0;
}