#include <iostream>

using std::cout;
using PTR_FUNC = bool (*)(double);     // тип указателя на функцию

bool any(const double* ar, size_t len, PTR_FUNC filter)
{
    bool res = false;
    for(int i = 0; i < len; ++i)
         res |= filter(ar[i]); 
    return res;
}

bool range_out(double x)
{
    return ! (x >= -0.5 && x <= 0.5);
}

int main()
{
    double ar[] = {0.1, 0.2, 0.3, -0.4, 1.4};
    bool res = any(ar, sizeof(ar) / sizeof(*ar), range_out);
    cout << std::boolalpha << res;

    return 0;
}