#include <iostream>

using PTR_FUNC = bool (*)(int);     // тип указателя на функцию

bool all(const int* ar, size_t len, PTR_FUNC filter)
{
    bool res = true;
    for(int i = 0; i < len; ++i)
         res &= filter(ar[i]);      // текущее res сравнивается с res_old, поэтому если хоть раз res = false, то true уже не будет
    return res;
}

bool positive(int x)
{
    return x > 0;
}

int main()
{
    int ar[] = {2, 3, 1, -10, 15};
    bool res = all(ar, sizeof(ar) / sizeof(*ar), positive);
    std::cout << res;

    return 0;
}