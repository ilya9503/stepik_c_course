#include <stdio.h>

struct tag_time {
    unsigned char hours;    // 1 байт = 2^8 = 0-255 бит
    unsigned char minutes;
    unsigned char seconds;
};

unsigned char sum(unsigned char n1, unsigned char n2)
{
    unsigned char sum = n1 + n2;
    if(sum > 59)
        sum = sum - 60;
    return sum;
}

int overflow(unsigned char n1, unsigned char n2)
{
    return (n1 + n2) <= 59 ? 0 : 1;
}

int main(void)
{
    // здесь продолжайте программу
    struct tag_time tm1 = {.hours = 12, .minutes = 45, .seconds = 16}, tm2 = {.hours = 4, .minutes = 23, .seconds = 48}, tm_sum;
//    scanf("%hhu %hhu %hhu %hhu %hhu %hhu", &tm1.hours, &tm1.minutes, &tm1.seconds, &tm2.hours, &tm2.minutes, &tm2.seconds);
    tm_sum.seconds = sum(tm1.seconds, tm2.seconds);

    tm_sum.minutes = sum(tm1.minutes, tm2.minutes);
    if(overflow(tm1.seconds, tm2.seconds)) ++tm_sum.minutes;

    tm_sum.hours = sum(tm1.hours, tm2.hours);
    if(overflow(tm1.minutes, tm2.minutes)) ++tm_sum.hours;

    printf("%02d:%02d:%02d", tm_sum.hours, tm_sum.minutes, tm_sum.seconds);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}