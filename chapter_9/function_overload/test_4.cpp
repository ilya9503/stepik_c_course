#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int min2(int n1, int n2)
{
    return n1 < n2 ? n1 : n2;
}

double min2(double n1, double n2)
{
    // Метод сравнения с допуском
    //double epsilon = 1e-9;  // константа допуска
    //return std::fabs(n1 - n2) < epsilon;
    return n1 < n2 ? n1 : n2;
}

int main()
{
    int n1;
    double n2;
    cin >> n1 >> n2;
    cout << fixed << setprecision(1) << min2((double)n1, n2) << endl;

    return 0;
}