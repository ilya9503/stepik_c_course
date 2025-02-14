/*
    Объект-строка string в С++
    тип (класс) std::string основан на динамическом массиве символов (char)
    std::string - class.
        typedef basic_string<char> string;
        Strings are objects that represent sequences of characters.
    
*/

#include <iostream>
#include <string>   // std::string

using std::cout;
using std::cin;
using std::endl;


int main()
{
    char msg_c[] = "Hello, World!";     // строка в языке С
    std::string msg_cpp {"Hello, Ilya Savchenko!"};        // объект-строка в языке С++. Объект класса string

    /*
        Методы класса string:
            size() - фактическое количество символов в строке
            capacity() - размер динамического массива (кол-во эл-тов, символов)
            std::string::size - Returns the length of the string, in terms of bytes.
            std::string::capacity - Returns the size of the storage space currently allocated for the string, expressed in terms of bytes.
            std::string::data - Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.
    */
    cout << msg_cpp.size() << " " << msg_cpp.capacity() << endl;
    cout << msg_cpp << endl;

    const char* data = msg_cpp.data();
    printf("%s\n", data);

    return 0;
}