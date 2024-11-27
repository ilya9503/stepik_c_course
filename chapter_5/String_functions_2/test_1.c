#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int h, m, s;
    clock_t t;
    t = clock();        // начало отсчета
    scanf("%d %d %d", &h, &m, &s);
    char res[100];

    char format[] = "%02d:%02d:%02d";
    if(!(h >= 0 && h <= 23)) {
        strcpy(format, "--:%02d:%02d");
        sprintf(res, format, m, s);
    }
    else if(!(m >= 0 && m <= 59)) {
        strcpy(format, "%02d:--:%02d");
        sprintf(res, format, h, s);
    }
    else if(!(s >= 0 && s <= 59)) {
        strcpy(format, "%02d:%02d:--");
        sprintf(res, format, h, m);
    }
    else
        sprintf(res, format, h, m, s);

    puts(res);

    
    t = clock() - t;    // конец отсчета
    printf("Time elapsed: %d clock ticks and %f seconds", t, (float)t / CLOCKS_PER_SEC);

    return 0;
}