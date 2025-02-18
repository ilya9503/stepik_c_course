#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;

int main()
{
    ifstream fs("my_marks.dat");

    if(!fs) {
        std::cout << "Невозможно открыть файл";
        return 0;
    }

    short marks[10] = {0};
    int count = 0;
    while(count < 10 && fs >> marks[count])
        count++;

    fs.close();

    for(const int& x : marks)
        std::cout << x << " ";

    return 0;
}