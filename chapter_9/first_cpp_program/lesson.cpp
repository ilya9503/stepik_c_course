// Первая программа на языке С++
// Однострочный комментарий
/*
    Будем использовать стандарт -std=c++14
    Ключевое слово std – это предопределенное название пространства имен, так называемой, стандартной библиотеки языка С++
    В язык С++ на уровне стандарта включили библиотеку STL, которая заметно упрощает работу со сложными коллекциями
        и типами данных, таких как:
    строки (std::string);
    массивы (std::array);
    динамический массив (std::vector);
    двухсвязный список (std::list);
    очередь (std::deque);
    упорядоченные множества (std::set);
    упорядоченные ассоциативные массивы (std::map)    
*/
#include <iostream>
// #include <stdio.h> // на С

int main()
{
    // printf("Hello World!");
    // std::cout - объект класса cout ostream
    // endl - добавляет в поток \n и очищает его flush()
    std::cout << "Hello World!" << std::endl;
    return 0;
}