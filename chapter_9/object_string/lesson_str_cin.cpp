#include <iostream>
#include <string>
 
using std::cout;
using std::cin;
using std::endl;
 
int main()
{
    std::string msg;
    //cin >> msg;             // прочитает вводимую строку до символа пробела ' '
    getline(cin, msg, ';');   // прочитает вводимую строку до символа перевода строки '\n' (или до символа в 3 параметре)
    cout << msg << endl;
    return 0;
}