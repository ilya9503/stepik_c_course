/*
    Bubble sort
    Complexity: O(n^2)
    Попарное сравнение --> замена эл-тов --> продвижение до конца массива
    n-1, потому что в конце алгоритма, самый первый элемент в любом случае будет наименьшим,
        остальные n-1 элементов будут больше
    1-ый проход:
        Наибольший элемент в конец
*/
#include <iostream>
#define LENGTH  20

namespace array_alg {
typedef enum {
    sort_asc,   // сортировка по возрастанию
    sort_desc   // сортировка по убыванию
} TYPE_SORT;

int int_swap(int* n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
    return 1;
}

void sorted_int(int* ar, size_t len_ar, TYPE_SORT type)
{
    for (int i = 0; i < len_ar - 1; i++) {  // n-1, 1-ый элемент будет наименьшим в любом случае
        int swapped = 0;
        // отнимаем i, тк после каждого прохода 1 элмент встает на свое место
        for (int j = 0; j < (len_ar - i - 1); j++) {    // до предпоследнего эл-та, чтобы не выйти за границы массива
            switch (type) {
            case sort_asc:
                if (ar[j] > ar[j + 1])
                    swapped = int_swap(&ar[j], &ar[j + 1]);
                break;
            case sort_desc:
                if (ar[j] < ar[j + 1])
                    swapped = int_swap(&ar[j], &ar[j + 1]);
                break;
            }
        }
        if (!swapped) break; // Если обменов не было, массив уже отсортирован
    }
}

void print_array(int* ar, int q)
{
    for (int i = 0; i < q; ++i)
        std::cout << ar[i] << ' ';
    std::cout << std::endl;
}

}

int main()
{
    int ar[LENGTH];
    int count = 0;
    while (count < LENGTH && std::cin >> ar[count])
        ++count;
    
    array_alg::sorted_int(ar, count, array_alg::sort_desc);
    array_alg::print_array(ar, count);
    
    return 0;
}