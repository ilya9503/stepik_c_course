#include <iostream>

enum {max_size = 20};

void swap(short& val1, short& val2)
{
    short temp = val1;
    val1 = val2;
    val2 = temp;
}

void reverse(short* ar, size_t len)
{
    size_t ind = len-1;
    for(int i = 0; i < (len/2); ++i)
        swap(ar[i], ar[ind--]);
}

int main()
{
    short digs[max_size];
    int count = 0;
    while(count < max_size && std::cin >> digs[count])
        count++;

    // здесь продолжайте программу
    reverse(digs, count);
    for(int i = 0; i < count; ++i)
        std::cout << digs[i] << " ";
    std::cout << std::endl;

    return 0;
}