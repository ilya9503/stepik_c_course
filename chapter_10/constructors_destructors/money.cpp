#include <iostream>

// здесь объявляйте структуру
struct money {
private:
    int total_money;
public:
    money(int total_money=0) { this->total_money = total_money; }
    ~money() {}
    int get_money() { return this->total_money; }
    void set_money(int volume) { this->total_money = volume; }
};

int main(void)
{
    money rubs{100};
    std::cout << rubs.get_money() << std::endl;
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}