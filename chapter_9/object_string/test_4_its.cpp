#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    // здесь продолжайте программу
    string msg;
    std::getline(cin, msg, '\n');
    int count = 0;
    auto i = msg.cend();      // возвращает const_iterator, не позволяет менять содержимое в отличие от end()
    i--;
    //cout << *i << '\n';     // cend() выведет past-the-end символ, те \0
    while (count++ < 3)
        cout << *i--;
    cout << endl;

/*
    Решение с использованием метода rbegin()
    Returns a reverse iterator pointing to the last character of the string
    auto определит 

    for(auto it = msg.rbegin(); it < (msg.rbegin() + 3); ++it )
        putchar(*it);
*/
    
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}