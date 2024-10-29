#include <stdio.h>

int main()
{
    
    int ar[10];
    int count = 0;
    while(count < 10 && scanf("%d", &ar[count]) == 1)
        count++;
//    printf("%d\n", count);

    int res = 1;
    for(int i = 0;i < count; ++i)
        res = res && (ar[i] > 0 && ar[i] % 2 == 1);

    printf("%d", res);

    int a = 5, b = 7;
    double d = 2.0;
    int* ptr_a = &a, *ptr_b = &b;

    ptr_a += 3;
//    ptr_b + ptr_a;
//    ptr_a /= b;
//    ptr_b += ptr_a;
    ptr_b - ptr_a;
    ptr_a += b * 5;
//    ptr_b -= ptr_a;
    --ptr_a;
//    ptr_a *= a;
    ptr_b++;
//    ptr_a -= d;


    return 0;
}