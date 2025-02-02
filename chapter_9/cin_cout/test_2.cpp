#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;

    if(!(a < b)) {
        std::cout << "Incorrect input!";
        return 1;
    }

    for (int i = a; i <= b; ++i)
        if(i % 3 == 0)
            std::cout << i << ' ';
    
    return 0;
}