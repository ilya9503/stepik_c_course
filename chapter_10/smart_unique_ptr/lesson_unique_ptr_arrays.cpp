/*
    Указатели unique_ptr можно определять и на массивы
*/

#include <iostream>
#include <memory>
 
using std::cout;
using std::endl;
 
int main(void)
{
    unsigned total {10};
    std::unique_ptr<int[]> ar {std::make_unique<int[]>(total)};     // массив из 10 элементов типа int
    auto ar_2 {std::make_unique<int[]>(7)};                         // тоже самое, но с вычисляемым типом (краткая запись)
    std::unique_ptr<int[]> ar_3 {nullptr};                          // Инициализация потом

    // Запишем значения в массив ar
    for(int i = 0; i < total; ++i)
        ar[i] = i*i;    // Обращаемся к указателю так же как и к массиву

    // Вывод массива ar в консоль
    for(int i = 0; i < total; ++i)
        cout << ar[i] << " ";

    return 0;
}