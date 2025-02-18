#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;

int main()
{
    ofstream fs("my_marks.dat");

    if(!fs) {
        std::cout << "Невозможно открыть файл";
        return 0;
    }

    short marks[] = {3, 3, 2, 3, 4, 3, 2};
    for(int i = 0; i < sizeof(marks) / sizeof(*marks); ++i)
        fs << marks[i] << "; ";

    fs.close();

    return 0;
}