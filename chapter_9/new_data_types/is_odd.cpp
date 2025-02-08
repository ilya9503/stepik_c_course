#include <iostream>
#define MAX_LEN     20

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int x[MAX_LEN]; // можно без массива
    int count = 0;
    bool fl_even = true;

    while (cin >> x[count] && x[count])     // читаем зн-я, пока не ввели 0
        ++count;

    for (int i = 0; fl_even && i < count; ++i)
        fl_even &= !(x[i] % 2);

    fl_even ? cout << "even" : cout << "no";
    cout << endl;

    return 0;
}