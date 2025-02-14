/*
    Объект-строка string
        Инициализация объекта-строки
        Обращение через оператор []
        Некоторые методы класса string
        Способы итерации строки через цикл for

*/

#include <iostream>
#include <string>   // std::string

using std::cout;
using std::cin;
using std::endl;


int main()
{
    std::string msg {"Hello, Ilya Savchenko!"};     // объект-строка в языке С++. Объект класса string
    std::string fio {"Savchenko Ilya Igorevich"};
    std::string fio_new {fio};                      // данные из fio копируются в fio_new

    cout << fio_new << endl;
    fio_new[12] = 'i';              // заменяем один символ в fio_new
    cout << fio_new << endl;
    cout << fio_new[0] << endl;     // выведет 1-ый символ

    /*
        range-based for loop C++11
        for(<тип переменной> <переменная> : <коллекция>) {}
            Если нужно изменять элементы коллекции, используем ссылку &
            Если не нужно изменять, передаем обычную переменную (передача аргумента по значению - копирование)
    */
    for(const char& ch : fio)       // по-символьный перебор с новым циклом for для коллекций
        cout << ch << " ";
    cout << endl;

    /*
        Перебор с использованием механизма итерации
        std::string::begin - returns an iterator pointing to the first character of the string.
        std::string::cend - returns a const_iterator pointing to the past-the-end character of the string.
        auto - вычисляемый тип
    */
    for(auto it = fio.cbegin(); it != fio.cend(); ++it)
        cout << *it << " ";
    cout << endl;

    /*
        Классический способ перебора строки, как в языке С
    */
    const char* ptr_str = fio.data();
    for(int i = 0; ptr_str[i] != '\0'; ++i)
        cout << ptr_str[i] << " ";
    cout << endl;

    return 0;
}