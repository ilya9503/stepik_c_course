/*
    Захват переменных по ссылке и указателю

    Если же нам нужно внутри лямбда-выражения оперировать непосредственно внешними локальными переменными,
        то их следует передавать либо по ссылке, либо через указатели.
    Начнем с захвата внешних переменных по ссылкам.
        Для этого в квадратных скобках вместо символа ‘=’ прописывается символ ссылки ‘&’

    Этот пример также показывает, что в квадратных скобках мы можем комбинировать запись через
        присваивание и через ссылки. Мало того, можно даже использовать и такие виды записей:

        [&a, b, &m, n]  // a и m – по ссылке; b и n – по значению
        [=, &m, &n]     // все по значению; m и n – по ссылке
        [&, m, n]       // все по ссылке; m и n – по значению
*/

#include <iostream>
 
using std::cout;
using std::cin;
using std::endl;
 
const int max_size = 1000;  // глобальная переменная
 
int main()  // локальная функция
{
    int data[] {1, 2, 3, 4, 5, 6, 7, 8};
    size_t sz = sizeof(data)/sizeof(*data);
    size_t *ptr_sz = &sz;
 
    auto r = [ptr_sz, &data]() {
        (*ptr_sz)++;
        cout << *ptr_sz << endl; 
        for(int& x : data)
            cout << ++x << " ";
        cout << endl; 
    };
 
    r();
 
    cout << sz << endl;
    for(int x : data)
        cout << x << " ";
    cout << endl;

 
    return 0;
}