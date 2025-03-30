/*
    Начиная со стандарта C++20 указатели shared_ptr можно инициализировать и использовать с
        динамическими массивами.
    Делается это по аналогии с указателями unique_ptr следующим образом:
*/

#include <iostream>
#include <memory>       // заголовок для умных указателей unique_ptr, shared_ptr

int main()
{
    unsigned total = 10;
    std::shared_ptr<int> ar_1 {std::make_shared<int[]>(total)};
    ar_1[0] = 10;
    
    for(unsigned i = 0;i < total; ++i)
        std::cout << ar_1[i] << " ";

    return 0;
}