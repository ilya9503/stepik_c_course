#include <iostream>

int main()
{
    long ar[] = {2, 4, 8, 16, 3, 9, 27, 81, -10, -100, -1000};
    size_t len = sizeof(ar) / sizeof(*ar);

    for(long x : ar)
        std::cout << x << " ";
/*
    int count = 0;
    do {
        std::cout << ar[count++] << " ";
    } while(count < len);
*/

    return 0;
}