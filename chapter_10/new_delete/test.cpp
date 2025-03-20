#include <math.h>
int module_id = -1;

namespace params {
int global_result = 0;
}

namespace triangle {
double square(int a, int b, int c)
{
    double p = (a+b+c) / 2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
}

namespace params {
typedef union {
    int res_int;
    double res_dbl;
} RESULT;
}

int main()
{
    ::module_id;
    params::global_result;
    params::RESULT f;
}