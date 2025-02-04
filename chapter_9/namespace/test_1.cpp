#include <iostream>

namespace triangle {
int perimetr(int a, int b, int c)
{
    return a + b + c;
}
}

namespace rectangle {
int perimetr(int width, int height)
{
    return 2 * (width + height);
}
}

int main()
{
    int a0, a1, a2;
    std::cin >> a0 >> a1 >> a2;
    std::cout << triangle::perimetr(a0, a1, a2) << ' ';
    std::cout << rectangle::perimetr(a0, a1) << std::endl;

    return 0;
}