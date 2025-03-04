#include <iostream>

enum {max_length_ar = 20};
using filter_func = bool (*)(short);

void remove_elem(short* ar, int& len, filter_func filter)
{
    // здесь продолжайте функцию
    for (int i = 0; i < len; ++i) {
        if(filter(ar[i])) {
            for(int j = i; j < len-1; ++j)
                ar[j] = ar[j+1];
            --len;
            --i;
        }
    }  
}

int main(void)
{
    short marks[max_length_ar] = {0};
    int count = 0;
    while(count < max_length_ar && std::cin >> marks[count])
        count++;

    // здесь продолжайте функцию main
    remove_elem(marks, count, [] (short x) -> bool {return x < 3;});

    for(int i = 0; i < count; ++i)
        std::cout << marks[i] << ' ';
    std::cout << std::endl;

    return 0;
}