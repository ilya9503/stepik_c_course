#include <iostream>

enum {max_size_ar=20};

int main()
{
    short data[max_size_ar];

    // здесь продолжайте программу
    int count = 0;
    while(count < max_size_ar && std::cin >> data[count]) {
        std::cin.ignore(1, ';');
        ++count;
    }
        

    for (int i = 0; i < count; ++i)
        std::cout << data[i] << ' ';
    
    //std::cin.ignore()
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}