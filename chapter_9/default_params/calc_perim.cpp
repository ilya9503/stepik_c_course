#include <iostream>

using calc_type = enum {calc_perimetr, calc_square};

int get_rect_value(int width, int length, calc_type type=calc_perimetr)
{
    int res {0};
    switch (type) {
        case calc_square:
            res = width * length;
            break;
        default:
            res = (width + length) * 2;
            break;
    }
    return res;
}

int main()
{
    int w, l;
    std::cin >> w >> l;
    std::cout << get_rect_value(w, l) << std::endl;

    return 0;
}