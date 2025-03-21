#include <iostream>

struct box {
    unsigned short a, b, c;
    box() { std::cout << "Empty box" << std::endl; }
    box(unsigned short a, unsigned short b, unsigned short c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        std::cout << "Box: " << a << ", " << b << ", " << c << std::endl;
    }
};

int main(void)
{
	// здесь продолжайте функцию main
    box* ar_box = new box[5] {
        {1, 2, 3},
        {6, 2, 1},
        {0, 0, 0},
        {11, 13, 19},
        {23, 5, 7}
    };

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)

    // здесь освобождайте памяти из под массива
    delete [] ar_box;
    ar_box = nullptr;

    return 0;
}