#include <iostream>

enum {max_length_ar = 20};
using filter_func = bool (*)(int, int);

int sum_elem(const int* ar, size_t len, filter_func filter)
{
    int sum = 0;
    // здесь продолжайте функцию
    for(int i = 0; i < len; ++i) {
        if(i > 0 && filter(ar[i-1], ar[i]))
            sum += ar[i];
    }
    return sum;
}

int main(void)
{
    int marks[max_length_ar] = {0};
    int count = 0;
    while(count < max_length_ar && std::cin >> marks[count])
        count++;

    // здесь продолжайте функцию main
    std::cout << sum_elem(marks, count, [] (int x_p, int x) {return !(x_p % 2) && !(x % 3);}) << std::endl;

    return 0;
}