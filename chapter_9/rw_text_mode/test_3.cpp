#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;

int main()
{
    short sh = 10;
    double d = -0.56;
    char ch = 'a';
    
    ofstream ofs("my_data.dat");

    if(!ofs) {
        std::cout << "Невозможно открыть файл";
        return 0;
    }

    // здесь будет располагаться записанная команда
    ofs << sh << " " << d << " " << ch;

    ofs.close();

    return 0;
}