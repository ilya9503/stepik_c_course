#include <stdio.h>
void angle_range_fc();

int main(void)
{
/*
    int angle, res, range = 360;
    scanf("%d", &angle);
    angle_range_fc(angle, range);

    int rect_width = 1280, rect_height = 720;
    int w = 8, h = 8;
    scanf("%d; %d", &w, &h);
    int res_w = rect_width % w;
    int res_h = rect_height % h;
    printf("%d %d", res_w, res_h);


    unsigned short time_h = 10; // часы
    unsigned short time_m = 33; // минуты
    unsigned short time_s = 5; // секунды

    unsigned short h, m, s; // добавляемое время: h - часы; m - минуты; s - секунды
    scanf("%hu; %hu; %hu", &h, &m, &s);

    unsigned int time_sec_old = time_h * 3600 + time_m * 60 + time_s;
    unsigned int time_sec_add = h * 3600 + m * 60 + s;
    unsigned int time_sec_new = time_sec_old + time_sec_add;


    s = time_sec_new % 60;
    m = (time_sec_new / 60) % 60;
    h = time_sec_new / 3600;

    printf("%02u:%02u:%02u\n", h, m, s);


    unsigned int time = 4 * 3600 + 32 * 60 + 18;
    // часы : минуты : секунды
    unsigned int sec = time % 60;
    unsigned int min = (time / 60) % 60;
    unsigned int hour = time / 3600;

    printf("%02d:%02d:%02d\n", hour, min, sec);
    
    double r;
    scanf("%lf", &r);
    printf("%.1f", --r);

    int h, w;
    scanf("%d, %d", &h, &w);
    printf("%d", ++h * ++w);
*/
    int rect_width = 640, rect_height = 480;
    int w = 1, h = 1;
    scanf("%d; %d", &w, &h);

    int sq_rec = w * h;
    int sq_main = rect_width * rect_height;
    int res = sq_main / sq_rec;
    int res_1 = (rect_width / w) * (rect_height / h);
    int remain = sq_main % sq_rec;

    printf("%d %d %d", res, remain, res_1);


    return 0;
}



void angle_range_fc(int angle, int range)
{
    int res;
    printf("%d", res = angle % range);
    return;
}