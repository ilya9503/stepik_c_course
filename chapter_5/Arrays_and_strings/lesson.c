#include <stdio.h>

#define SIZE_BUFFER     1024

int main(void)
{
    // Корректные объявления массивов
    double f[30];
    char buffer[SIZE_BUFFER];
    int marks[13];
    short ar[8 * 5];
    char bytes[sizeof(double)];

    // Некорректные объявления массивов
    int n;

    int array[n];
    float func[21.5];
    int null_ar[0];





    return 0;
}