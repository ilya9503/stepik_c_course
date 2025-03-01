#include <iostream>

enum {max_size = 20};

inline bool is_even(int x)
{
    return ! (x % 2);
}

int sum_ar(const int *ar, size_t len_ar, bool (*func)(int))
{
    // здесь продолжайте функцию
    int res = 0;
    for(int i = 0; i < len_ar; ++i)
        res += func(ar[i]) ? ar[i] : 0;
    return res;
}

int main()
{
    int marks[max_size] = {0};
    int count = 0;
    while(count < max_size && std::cin >> marks[count++]);
    std::cout << sum_ar(marks, max_size, is_even) << std::endl;

    return 0;
}