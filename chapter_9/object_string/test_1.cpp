#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	// здесь продолжайте программу
    string fname, lname;
    cin >> fname >> lname;
    string fio = fname + ", " + lname;
    cout << fio << endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}