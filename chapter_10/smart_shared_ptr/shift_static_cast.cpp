/*
    static_cast в C++
    static_cast — это один из операторов приведения типов в C++, который выполняет явное преобразование типов во время компиляции.
        Он используется для безопасного и предсказуемого преобразования между совместимыми типами.
*/
#include <iostream>
#include <memory>

int main(void)
{
    int x;
    std::cin >> x;

    // здесь продолжайте функцию main
    std::shared_ptr<short> p_val {std::make_shared<short>(x)};

    unsigned char low = *p_val & 0xFF;           // Младший байт
    unsigned char high = (*p_val >> 8) & 0xFF;   // Старший байт

    std::cout << static_cast<int>(low) << " " << static_cast<int>(high) << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}