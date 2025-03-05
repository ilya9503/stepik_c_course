#include <iostream>

int main(void)
{
    int count = 1;
    int& lnk = count;
    // несмотря на то, что lnk изначально ссылка, 
    // в лямбду она передается по значению, поэтому как ссылка она не работает
    auto r = [lnk] (int step) mutable { lnk += step; };

    r(5);
    std::cout << count << std::endl;

    return 0;
}