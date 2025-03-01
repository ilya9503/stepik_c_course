#include <iostream>

enum{max_len = 10};

inline int sum_ar_int(int* ar, size_t len)
{
    int res = 0;
    for(int i = 0; i < len; ++i)
        res += ar[i];
    return res;
}

int main()
{
    // здесь продолжайте функцию main
    int ar[max_len];
    int count = 0;
    while (count < max_len && std::cin >> ar[count++]);
    std::cout << sum_ar_int(ar, max_len) << std::endl;
    
    return 0;
}