#include <stdio.h>
#include <math.h>

int main(void)
{
    int m, n, k;
    double s = 0.0;
    scanf("%d %d %d", &m, &n, &k);

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int t = 1; t <= k; ++t) {
                s += pow(j, 2) / (pow(i + t, 3) - t);
            }
        }
    }
    
    printf("%.4f", s /= (n + m + k));




    return 0;
}