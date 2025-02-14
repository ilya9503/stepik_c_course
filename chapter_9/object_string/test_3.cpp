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
    for(int i = 0; i < 4; ++i)
        putchar(msg[i]);
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}