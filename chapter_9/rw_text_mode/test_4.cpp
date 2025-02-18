#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;

int main()
{
    short sh;
    double d;
    char ch;
    
    ifstream ifs("my_data.dat");

    if(!ifs) {
        std::cout << "Невозможно открыть файл";
        return 0;
    }

    // здесь будет располагаться записанная команда
    ifs >> sh >> d >> ch;
    std::cout << sh << " " << d << " " << ch << std::endl; 

    ifs.close();

    return 0;
}