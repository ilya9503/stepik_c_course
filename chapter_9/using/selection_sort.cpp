#include <iostream>

enum {max_length = 50, max_things = 20};

using std::cin;
using std::cout;
using std::endl;
using THING = struct {
    char name[max_length];
    double weight;
};

namespace alg {
// Функция замены структур
int THING_swap(THING* n1, THING* n2)
{
    THING temp = *n1;
    *n1 = *n2;
    *n2 = temp;
    return 1;
}

// Вывод в консоль имен структуры
void print_array_THINGs(THING* ar, int q)
{
    for (int i = 0; i < q; ++i)
        std::cout << ar[i].name << ' ';
    std::cout << std::endl;
}

// Сортировка выбором
void selectionSort(THING* th, size_t size) {
    /*
        1. Начинаем с 0 индекса
        2. Находим минимальный эл-нт в оставшемся массиве
        3. Меняем местами текущий элемент и минимальный
    */
    // Передвигаемся вперед, в начале массива хранятся отсортированные элементы
    for (int i = 0; i < size - 1; ++i) {
        // Текущая позиция = минимальный индекс. Начинаем с 0 индекса
        // Ищем от
        int min_idx = i;    
        // Ищем минимальный элемент (индекс) в оставшемся неотсортированном массиве
        for (int j = i + 1; j < size; ++j) {
            if (th[j].weight < th[min_idx].weight) {
                min_idx = j; // обновляем минимальный индекс, если нашелся элемент меньше текущего 
            }
        }
        // Заменяем текущий элемент минимальным
        THING_swap(&th[i], &th[min_idx]);
    }
}

}
using namespace alg;
/*
    1. Кол-во строк = кол-во весов
    2. Нужно отсортировать массив типа THING
*/

int main()
{
    THING th[max_things];
    int count = 0;
    while((count < max_things) && (cin >> th[count].name >> th[count].weight))
        ++count;

    alg::selectionSort(th, count);
    //print_array_THINGs(th, count);
        for (int i = 0; i < count; ++i)
            cout << th[i].name << ' ';
        cout << endl;
    

    return 0;
}