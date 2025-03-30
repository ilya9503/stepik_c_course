#include <iostream>
#include <memory>

enum {max_size_ar = 10};

using shared_ari_ptr = std::shared_ptr<int[]>;  // указатель 

int sum_ar(const shared_ari_ptr& ar, size_t len)
{
    // здесь продолжайте функцию sum_ar
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += ar[i];
    return sum;
}

int main(void)
{
    shared_ari_ptr ar {new int[max_size_ar] {0}};
    //shared_ari_ptr ar {std::make_shared<int[]>(max_size_ar)};
    
    unsigned count = 0;

    // здесь продолжайте функцию main
    while(count < max_size_ar && std::cin >> ar[count])
        ++count;

    std::cout << sum_ar(ar, max_size_ar) << std::endl;

    return 0;
}