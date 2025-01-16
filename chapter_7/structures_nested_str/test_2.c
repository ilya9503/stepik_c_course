#include <stdio.h>


struct tag_price {
    char name[100];
    unsigned int rubs;
    unsigned short kops;
    unsigned int foreign_key;
};


int main(void)
{
    // здесь продолжайте функцию main
    struct tag_price pr;
    //pr = price_100;

    printf("%s %u %hu %hd", pr.name, pr.rubs, pr.kops, pr.foreign_key);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}