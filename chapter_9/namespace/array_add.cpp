#include <iostream>

namespace array_alg {
typedef int (*PTR_FILTER_FUNC)(int);
/*
    Добавляет в конец массива только определенные значения из другого массива
        src - массив, в который добавляются новые значения; 
        start - начальный индекс, с которого происходит добавление в массив src; 
        max_len_src - длина массива src; 
        dest - массив, из которого добавляются значения;
        len_dest - количество добавляемых элементов из массива dest в массив src;
        func - указатель на функцию для отбора (фильтрации) значений массива dest.
    Возвращает новую результирующую длину массива src

*/ 
size_t add_int(int* src, size_t start, size_t max_len_src, const int* dest, size_t len_dest, PTR_FILTER_FUNC func)
{
    size_t res_len = start;
    size_t d_index = 0;
    // перебираем массив src от start
    // dest от 0
    for (int i = 0; (i < len_dest) && (i < max_len_src); ++i) {
        if (func(dest[d_index])) {
            src[res_len] = dest[d_index];
            ++res_len;
        }
        ++d_index;
    }
    return res_len;
}

void print_array(int* ar, int q)
{
    for (int i = 0; i < q; ++i)
        std::cout << ar[i] << ' ';
    std::cout << std::endl;
}

namespace filter_func {
int mark_positive(int x)
{
    return (x >= 4) ? 1 : 0;
}

}
}

int main()
{
    int marks[100] = {3, 2, 5, 4, 3};
    int ar[20];
    size_t count = 0, count_marks = 5;

    // здесь продолжайте функцию main
    size_t size_marks = sizeof(marks) / sizeof(*marks);
    while (count < 20 && std::cin >> ar[count])
        ++count;

    count = array_alg::add_int(marks, count_marks, size_marks, ar, count, array_alg::filter_func::mark_positive);
    array_alg::print_array(marks, count);

    return 0;
}