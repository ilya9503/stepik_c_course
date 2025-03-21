#include <iostream>

struct complex {
    double re, im;
};

int main(void)
{
	// здесь продолжайте функцию main
    complex* vc = new complex[7]();
    
    std::cout << vc[0].im << " " << vc[0].re << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    // здесь освобождайте памяти из под массива
    delete [] vc;
    vc = nullptr;

    return 0;
}