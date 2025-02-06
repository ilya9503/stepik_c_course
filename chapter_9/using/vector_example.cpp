/*
    vector — это динамический массив в C++ из библиотеки <vector>.
    Он автоматически изменяет свой размер при добавлении или удалении элементов.
    Позволяет динамически работать с массивами, добавлять, удалять и изменять данные
        без необходимости вручную управлять памятью.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;        // Пустой вектор для целых чисел

    numbers.push_back(5);       // Добавление элементов
    numbers.push_back(10);
    numbers.push_back(15);

    cout << "Элементы вектора: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    cout << "\nРазмер вектора: " << numbers.size() << endl;

    numbers.pop_back();     // Удаляем последний элемент

    cout << "После удаления последнего элемента: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    return 0;
}