#include <iostream>
#include <math.h>
#include <iomanip>


enum {max_length_1 = 200, max_length_2 = 100, ar_length = 10};

struct book {
    char title[max_length_1];
    char author[max_length_2];
    int price;
    int npages;
    double price_per_page() { return (double)price / (double)npages; }
};

int main()
{
    book lib[ar_length];
    int count {0};

    while(count < ar_length && std::cin.getline(lib[count].title, max_length_1)) {
        std::cin.getline(lib[count].author, max_length_2);
        std::cin >> lib[count].price >> lib[count].npages;
        std::cin.ignore();
        ++count;
    }
    
    std::cout << std::fixed << std::setprecision(2);
 
    for(int i = 0; i < count; ++i) {
        std::cout << lib[i].price_per_page() << ' ';
    }
    
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    return 0;
}