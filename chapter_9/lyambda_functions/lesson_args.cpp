/*
    Преимущество лямбда-выражения в этом примере перед обычной функцией еще и в том,
    что это выражение для функции существует лишь при вызове show_ar() и автоматически пропадает после вызова.
    То есть, имеем экономию памяти и не нагромождаем программу лишними объявлениями функций.
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void show_ar(const int* ar, size_t length, bool (*filter_func)(int) = nullptr)
{
    for(int i = 0;i < length; ++i) {
        if(filter_func != nullptr) {
            if(filter_func(ar[i]))
                cout << ar[i] << " ";
        }
        else
            cout << ar[i] << " ";
    }
}

int main()
{
    int data[] {1, 2, 3, 4, 5, 6, 7, 8};
    // Добавим в качестве аргумента встроенную лямбда-функцию, в качестве фильтра для выводав
    show_ar(data, sizeof(data)/sizeof(*data), [](int x) {return x % 2 == 0;});
 
    return 0;
}