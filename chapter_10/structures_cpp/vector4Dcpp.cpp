#include <iostream>
#include <cmath>
#include <iomanip>

struct vector4D{
    double x, y, z, t;
    
    void read_data(FILE* stream, char sep=' ') {std::cin >> x >> sep >> y >> sep >> z >> sep >> t;}
    double length() {return sqrt(x*x+y*y+z*z+t*t);}
};

int main(void)
{
    vector4D v1, v2;
    
    v1.read_data(stdin, ';');
    v2.read_data(stdin, ';');
    
    std::cout << std::fixed << std::setprecision(3) << v1.length() << " " << v2.length() << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}