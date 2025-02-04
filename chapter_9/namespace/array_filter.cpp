#include <iostream>
#define MAX_LEN     20

namespace array_alg {

typedef int (*PTR_FILTER_FUNC)(int);    // тип указателя на функцию типа int

size_t filter_int(int* ar, size_t len_ar, PTR_FILTER_FUNC func)
{
    // Перебираем массив
    for (int i = 0; i < len_ar; ++i) {
        // Если значение нечетное, удаляем из массива
        if(!func(ar[i])) {
            // Сдвигаем массив влево, уменьшая длину
            for (int j = i; j < len_ar-1; ++j)
                ar[j] = ar[j+1];
        --len_ar;
        --i;
        }
    }
    return len_ar;
}

void print_array(int* ar, int q)
{
    for (int i = 0; i < q; ++i)
        std::cout << ar[i] << ' ';
    std::cout << std::endl;
}

inline namespace filter_func {

// Проверка четности
int even(int x)
{
    return (x % 2 == 0) ? 1 : 0;
}

}
}

int main()
{
    int ar[MAX_LEN] = {5, 34, 10, 4, 7, 8, 3, 2};
    int count = 0;
    while (count < MAX_LEN && std::cin >> ar[count])
        ++count;

    count = array_alg::filter_int(ar, count, array_alg::even);
    array_alg::print_array(ar, count);

    return 0;
}