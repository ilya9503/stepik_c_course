#include <iostream>
#include <string.h>
#define MAX_LENGTH  50

using MEASURE = struct {
    unsigned short width;
    unsigned short height;
    unsigned short depth;
};

using AUTO = struct {
    char model[MAX_LENGTH];
    unsigned short max_speed;
    double weight;
    MEASURE m;
};

int main()
{
    AUTO auto_sell;
    char model[50];
    unsigned short max_speed, width, height, depth;
    double weight;

    std::cin >> model >> max_speed >> weight >> width >> height >> depth;

    // здесь продолжайте функцию main
    // auto_sell = (AUTO){.max_speed=max_speed, .weight=weight, .m=(MEASURE){width, height, depth}};
    strncpy(auto_sell.model, model, MAX_LENGTH);
    auto_sell.weight = weight;
    auto_sell.max_speed = max_speed;
    auto_sell.m.width = width;
    auto_sell.m.height = height;
    auto_sell.m.depth = depth;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}