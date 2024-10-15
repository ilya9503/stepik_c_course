#include <stdio.h>
int reverse_number(int number);

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    for(int i = a; i <= b; i++)
       if (i == reverse_number(i))
        printf("%d ", reverse_number(i)); 
    return 0;
}

int reverse_number(int number){
    int n = 0;
    while (number) {
        n = 10 * n + number % 10;
        number /= 10;
    } return n;
}