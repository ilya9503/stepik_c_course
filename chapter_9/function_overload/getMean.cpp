#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

enum{ar_size = 100};

double get_mean(const short* d, const size_t len);
double get_mean(const int* d, const size_t len);
double get_mean(const double* d, const size_t len);

int main()
{
    short ar[ar_size]{0};
    int count = 0;
    while(count < ar_size && cin >> ar[count])
        ++count;
    cout << fixed << setprecision(2) << get_mean(ar, count) << endl;

    return 0;
}

double get_mean(const short* d, const size_t len)
{
    short sum = 0;
    for (int i = 0; i < len; ++i)
        sum += d[i];
    return (double)sum / (double)len;
}

double get_mean(const int* d, const size_t len)
{
    short sum = 0;
    for (int i = 0; i < len; ++i)
        sum += d[i];
    return (double)sum / (double)len;    
}

double get_mean(const double* d, const size_t len)
{
    short sum = 0;
    for (int i = 0; i < len; ++i)
        sum += d[i];
    return sum / len;    
}