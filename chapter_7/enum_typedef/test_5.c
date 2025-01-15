#include <stdio.h>
int main(){
    double* p1 = (void *)128000, *p2 = (void *)128064;  // тип double 64 бит
    // 128064 - 128000 = 64 байта. Указатель double 64 бит = 8 байт. 64 / 8 = 8
    int count = p2 - p1;
    printf("%p %p %.f %.f %p", p1, p2, *p1, *p2, count); //ответ
    return 0;
}