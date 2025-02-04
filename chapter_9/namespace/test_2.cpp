#include <iostream>

namespace math {
// Функция сравнения 2 массивов
int ar_compare(const short* a1, size_t len_a1, const short* a2, size_t len_a2)
{
    if(len_a1 != len_a2)
        return 0;
    for(int i = 0; i < len_a1; ++i)
        if(a1[i] != a2[i])
            return 0;
    return 1;
}    
}

int main(void)
{
    // здесь продолжайте функцию main
    short ar1[] = {1, 2, 3, 4, 5};
    short ar2[] = {1, 2, 5, 3, 4};
    size_t size_ar1 = sizeof(ar1) / sizeof(*ar1);
    size_t size_ar2 = sizeof(ar2) / sizeof(*ar2);
    int res = math::ar_compare(ar1, size_ar1, ar2, size_ar2);
    //std::cout << res << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}