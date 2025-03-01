#include <iostream>

enum{max_len = 10};

inline void range(int* ar, size_t len, int start, int stop, int step)
{
    // start,start+step,start+2⋅step,...    
    for(int i = 0; i < len; ++i) {
        int temp = start + step * i;
        if(temp >= stop)
            break;
        else
            ar[i] = temp;
    }
}

int main()
{
    // здесь продолжайте функцию main
    int ar[max_len] = {0};
    //int count = 0;
    //while (count < max_len && std::cin >> ar[count++]);
    //std::cout << sum_ar_int(ar, max_len) << std::endl;
    range(ar, max_len, -5, 10, 3);
    for(int x : ar)
        std::cout << x << ' ';
    std::cout << std::endl;
    
    return 0;
}