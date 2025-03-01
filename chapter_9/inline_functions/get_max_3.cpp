#include <iostream>

inline int get_max_3(int x, int y, int z)
{
    return (z < (x < y ? y : x)) ? (x < y ? y : x) : z;
}

int main()
{
    // здесь продолжайте функцию main
    int x, y, z;
    std::cin >> x >> y >> z;
    std::cout << get_max_3(x, y, z) << std::endl;

    return 0;
}