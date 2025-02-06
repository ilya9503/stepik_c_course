#include <iostream>

using choise = enum {max_length = 50, min_sort, max_sort};

using std::cin;
using std::cout;
using std::endl;
using THING = struct {
    char name[max_length];
    unsigned int weight;
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
void selectionSort(THING* th, size_t size, choise ch) {
    // Передвигаемся вперед, в начале массива хранятся отсортированные элементы
    for (int i = 0; i < size - 1; ++i) {
        int index = i;    
        // Ищем минимальный элемент (индекс) в оставшемся неотсортированном массиве
        for (int j = i + 1; j < size; ++j) {
            switch (ch) {
            case min_sort:
                // Обновляем минимальный индекс, если нашелся элемент меньше текущего 
                if (th[j].weight < th[index].weight)
                    index = j; 
                break;
            case max_sort:
                // Обновляем максимальный индекс, если нашелся элемент больше текущего 
                if (th[j].weight > th[index].weight)
                    index = j; 
                break;            
            }
        }
        // Заменяем текущий элемент минимальным
        THING_swap(&th[i], &th[index]);
    }
}

// Вывод в консоль, в зависимости от веса
void pack(THING* th, size_t th_size, size_t w)
{
    w *= 1000;          // вес в грамах
    size_t count = 0;   // счетчик найденных предметов
    int index_max = 0;  // максимальный элемент
    // Перебираем отсортированный по убыванию массив
    for (int i = 0; w && i < th_size; ++i) {
        if(th[i].weight <= w) {
            w -= th[i].weight;
            THING_swap(&th[i], &th[count]);
            ++count;
        }
    }
    print_array_THINGs(th, count);    
}

}

int main()
{
    unsigned int max_weight;
    THING things[] = {  {"карандаш", 20}, {"зеркальце", 100}, {"зонт", 500}, {"рубашка", 300}, 
                        {"брюки", 1000}, {"бумага", 200}, {"молоток", 600}, {"пила", 400}, {"удочка", 1200},
                        {"расческа", 40}, {"котелок", 820}, {"палатка", 5240}, {"брезент", 2130}, {"спички", 10}};

    size_t things_size = sizeof(things) / sizeof(*things);
    
    cin >> max_weight;

    alg::selectionSort(things, things_size, max_sort);  // сортируем по убыванию
    alg::pack(things, things_size, max_weight);         // выводим по убыванию в зависимости от веса

    return 0;
}