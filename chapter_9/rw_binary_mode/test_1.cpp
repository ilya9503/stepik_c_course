#include <iostream>
#include <fstream>

using std::ios;

int main()
{
    short marks[] = {3, 3, 4, 3, 2, 2};

    std::ofstream ofs("my_data.dat", ios::out | ios::binary);

    if(!ofs) {
        std::cout << "Невозможно открыть файл";
        return 1;
    }

    ofs << "hello" << std::endl;
    ofs.write((char *)marks, sizeof(marks));

    ofs.close();
    return 0;
}