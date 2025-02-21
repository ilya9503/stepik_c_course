#define TOTAL   1024

int main(void)
{
    int total = 100;
    // здесь выполняются объявления
    
    unsigned short ar_1[100];

    double ar_2[5 * 3 - 2];
    
    long double ar_7[TOTAL / 2];
    
    long ar_5[0];
    
    short int ar_8[(int)(0.5 * 3)];
    
    signed char ar_4[total]; // (поддерживается не всеми компиляторами)
    
    float ar_3[sizeof(total) * 5];
    
    long long ar_6[0.5*2];

    return 0;
}