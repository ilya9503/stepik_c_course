#include <iostream>
#include <memory>

struct thing {
    unsigned long uid;
    unsigned width, height, depth;
};

int main(void)
{
    // здесь продолжайте функцию main
    std::unique_ptr<thing> p_th {std::make_unique<thing>()};
    p_th->uid = 1;
    p_th->width = 10;
    p_th->height = 43;
    p_th->depth = 108;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}