#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

struct vector4D {
    double x, y, z, t;
    void read_data(FILE* stream, char sep = ' ') {
        char mask[50];
        sprintf(mask, "%s%c %s%c %s%c %s", "%lf",sep,"%lf", sep,"%lf", sep,"%lf");
        fscanf(stream, mask, &x, &y, &z, &t);
    };
    double length() { return sqrt(x * x + y * y + z * z + t * t); };

};

int main()
{
    vector4D v1;
    vector4D v2;
    v1.read_data(stdin, ';');
    v2.read_data(stdin, ';');
    std::cout << std::fixed << std::setprecision(3) << v1.length() << ' ' << v2.length();
    
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}