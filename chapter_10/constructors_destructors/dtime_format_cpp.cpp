/*
Вариант 1:
    В std::format форматирование чисел делается по-другому, чем в printf.
    Строка "%02hhu" в printf означает:
        % — начало спецификатора.
        0 — дополнение нулями.
        2 — ширина 2 символа.
        hhu — unsigned char (выводится как целое число).

        std::cout << std::format("Число: {:04}", num) << std::endl;  
        // {:04} означает ширину 4 и дополнение нулями: "0042"
Вариант 2:
    std::ostringstream - поток для записи в строку
        std::setw(2) → устанавливает ширину в 2 символа.
        std::setfill('0') → заполняет неиспользованные позиции нулями (07, 05, 09).
        static_cast<int>(h) → приводит unsigned char к int, так как std::ostream интерпретирует char как символ.
*/
#include <iostream>
#include <string>
#include <format>   // Форматная строка С++20
#include <sstream>  // Форматная строка
#include <iomanip>

// здесь объявляйте структуру
struct dtime {
private:
    unsigned char hs, ms, sc;
public:
    // Конструктор
    dtime(unsigned char hours=0, unsigned char minutes=0, unsigned char seconds=0)
    {
        hs = hours;
        ms = minutes;
        sc = seconds;
    }
    // Деструктор
    ~dtime() {}
    // Собираем форматированную строку %02hhu
    void MakeStr(unsigned char x, std::string& str)
    {
        if(x < 10) {
            str.append(1, '0');
            str.append(1, static_cast<int>(x));
        } else {
            str.append(1, static_cast<int>(x));
        }
    }
    // Возвращает объект-строку std::string с содержимым (строкой) hh:mm:ss
    std::string get_time()
    {
        //"%02hhu:%02hhu:%02hhu", hours, minutes, seconds
        //std::string res = std::format("{:02}:{:02}:{:02}", hs, ms, sc);

        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << static_cast<int>(hs) << ":"
            << std::setw(2) << std::setfill('0') << static_cast<int>(ms) << ":"
            << std::setw(2) << std::setfill('0') << static_cast<int>(sc);
        std::string res = oss.str();

        return res;
    }
    // Задает время
    void set_time(unsigned char hours, unsigned char minutes, unsigned char seconds)
    {
        hs = hours;
        ms = minutes;
        sc = seconds;
    }
    // Формирует и возвращает новую структуру с суммой времен t1 и t2
    static dtime sum_time(const dtime& t1, const dtime& t2)
    {
        dtime tm_sum;
        tm_sum.sc = (t1.sc + t2.sc) % 60;
        tm_sum.ms = ((t1.ms + t2.ms) + (t1.sc + t2.sc) / 60) % 60;
        tm_sum.hs = ((t1.hs + t2.hs) + (((t1.ms + t2.ms) + (t1.sc + t2.sc) / 60) / 60)) % 24;
        return tm_sum;
    }
};

int main(void)
{
    // здесь продолжайте программу
    dtime tm1, tm2, time_res;
    unsigned int h1, m1, s1, h2, m2, s2;
    
    std::cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;

    tm1.set_time(h1, m1, s1);
    tm2.set_time(h2, m2, s2);

    time_res = dtime::sum_time(tm1, tm2);

    std::cout << time_res.get_time() << std::endl;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}