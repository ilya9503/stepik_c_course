#include <iostream>
#include <math.h>
#include <iomanip>  // std::setprecision, std::fixed

using std::cout;
using std::endl;
using std::cin;
using std::fixed;
using std::setprecision;

double get_square(int a, int b, int c)
{
    double p = (double)(a + b + c) / 2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int get_square(int a, int b)
{
    return a * b;
}

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << fixed << setprecision(1) << get_square(a, b, c) << " " << (double)get_square(d, e) << endl;

    return 0;
}