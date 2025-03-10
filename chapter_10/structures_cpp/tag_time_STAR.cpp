/*
    В C++ ключевое слово static для функций используется в двух основных контекстах:
        1. Внутри класса (член класса) – делает функцию независимой от экземпляра класса.
        2. В файле (глобальная функция) – ограничивает область видимости функции текущим файлом.
    Если использовать scanf, cout глючит
*/
#include <iostream>
#include <cstring>

enum{max_len = 10};

struct tag_time {
    unsigned char hours;
    unsigned char minutes;
    unsigned char seconds;
    // здесь объявляйте методы
    static bool digit_check(unsigned char x) { return x < 10 ? true : false; }
    static bool flag_ms(unsigned char x, unsigned char y) {return (x + y) >= 60 ? true : false; }
    static bool flag_hh(unsigned char x, unsigned char y) {return (x + y) >= 24 ? true : false; }
    static unsigned char sum_ms(unsigned char x, unsigned char y)
    { 
        unsigned char res = x + y;

        if(x == 60) {
            res = 0;
        }
        if(res > 60) {
            res = res - 60;
        }
        return res;
    }

    static unsigned char sum_hh(unsigned char x, unsigned char y)
    { 
        unsigned char res = x + y;
        if(x == 24) {
            res = 0;
        }
        if(res > 24) {
            res = res - 60;
        }
        return res;
    }

    char* get_time(char* str, size_t max_length)
    {
        char* temp = str;
        digit_check(hours) ? sprintf(temp, "0%hhu:", hours) : sprintf(temp, "%hhu:", hours);
        temp += 3;
        digit_check(minutes) ? sprintf(temp, "0%hhu:", minutes) : sprintf(temp, "%hhu:", minutes);
        temp += 3;
        digit_check(seconds) ? sprintf(temp, "0%hhu", seconds) : sprintf(temp, "%hhu", seconds);
        temp -= 6;  // возвращаем указатель в начало строки
        return temp;
    }

    // Можно пользоваться, не создавая объект структуры tag_time
    static tag_time sum_time(const tag_time& t1, const tag_time& t2)
    {
        tag_time temp{0, 0, 0};
        temp.seconds = sum_ms(t1.seconds, t2.seconds);
        if(flag_ms(t1.seconds, t2.seconds))
            ++temp.minutes;
        temp.minutes += sum_ms(t1.minutes, t2.minutes);
        if(flag_hh(t1.minutes, t2.minutes))
            ++temp.hours;        
        temp.hours += sum_hh(t1.hours, t2.hours);

        return temp;
    }

};

int main(void)
{
    // здесь продолжайте программу
    tag_time tm1, tm2, time_res;
    scanf("%hhu %hhu %hhu %hhu %hhu %hhu", &tm1.hours, &tm1.minutes, &tm1.seconds, &tm2.hours, &tm2.minutes, &tm2.seconds);

    char iStr[max_len] {0};
    time_res = tag_time::sum_time(tm1, tm2);
    std::cout << time_res.get_time(iStr, max_len) << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}