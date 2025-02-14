#include <iostream>
#include <string>

using std::string;
using std::to_string;   // для конвертации чисел в строки
using std::cin;
using std::cout;
using std::endl;

int main()
{
	// здесь продолжайте программу
    int width, height;
    cin >> width >> height;
    string data_str = "Переменная width = " + to_string(width) + ", переменная height = " + to_string(height);
    cout << data_str << endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}