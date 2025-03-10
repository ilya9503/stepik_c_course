#include <iostream>


struct tag_price {
    char name[100];
    unsigned int rubs;
    unsigned char kops;
    unsigned int foreign_key;
};


int main(void)
{
    // здесь продолжайте программу
    tag_price price_100;
    tag_price pr;
    pr = price_100;

    std::cout << pr.name << pr.rubs << (int)pr.kops << pr.foreign_key << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}