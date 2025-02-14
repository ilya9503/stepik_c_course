/*
    Метод класса string
        std::string::append - extends the string by appending additional characters at the end of its current value
*/

#include <iostream>
#include <string>   // std::string

using std::cout;
using std::cin;
using std::endl;


int main()
{
    std::string msg {"Hello"};      // объект msg класса string
    std::string name {"Ilya"};      // объект name класса string
    msg.append(", ");               // добавляем строку в конец msg, на подобие strncat()
    msg = msg + name;               // конкатинация
    /*  Варианты покороче  */
    //msg += name;
    //msg = msg.append(", ") + name;
    cout << msg << endl;    

    return 0;
}