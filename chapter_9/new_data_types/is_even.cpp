#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int x;
    bool fl_even = false;

    while (cin >> x && x) {     // читаем зн-я, пока не ввели 0
        fl_even |= (x % 2 == 0);
    }
    
    cout << (fl_even ? "even" : "no") << endl;

    return 0;
}