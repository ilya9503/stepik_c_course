#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);
    
    for(int i = 2, s = 1; i <= n; ++i) {    // перебираем натуральные числа
        if(n % i != 0)
            continue;

        while(s < n) {  // если i делит нацело n, проверяем делит ли нацело n i*i
            s *= i;

            if(n % s != 0) {
                break;
            }
            
            printf("%d ", i);
        }
         
        if(n == s)
            break;

        n /= i;
        printf("%d ", i);
    }

    return 0;
}