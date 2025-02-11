#include <iostream>
#include <typeinfo>


int main()
{
    short a = 1;
    const char symbol_f = 'f';
    const short* ptr_sh = &a;
    int count = 0;
    const int& lnk = count;

    auto var_1 = symbol_f;	
    auto var_2 = &symbol_f;	
    auto var_3 = ptr_sh;	
    auto var_4 = &count;	
    auto var_5 = lnk;	
    auto var_6 = *ptr_sh;

    std::cout << typeid(var_1).name() << "\n";
    std::cout << typeid(var_2).name() << "\n";
    std::cout << typeid(var_3).name() << "\n";
    std::cout << typeid(var_4).name() << "\n";
    std::cout << typeid(var_5).name() << "\n";
    std::cout << typeid(var_6).name() << "\n";

    // c
    // PKc
    // PKs
    // Pi
    // i
    // s

    return 0;
}