#include <iostream>

// здесь объявляйте структуру
struct triangle {
private:
    int a, b, c;
public:
    // Конструктор
    triangle(int a=0, int b=0, int c=0)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    // Деструктор
    ~triangle() {}
    // Проверка, является ли фигура треугольником
    bool is_triangle()
    {
        bool res {true};
        res = res && (a + b) > c;
        res = res && (a + c) > b;
        res = res && (b + c) > a;
        return res;
    }
    // Возвращает значения длин сторон из приватных переменных a, b, c
    void get_lengths(int& a, int& b, int& c)
    {
        a = this->a;
        b = this->b;
        c = this->c;
    }
    // Задает значения приватных переменных a, b, c
    void set_lengths(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};


int main(void)
{
    triangle tr_1;
    triangle tr_2(7, 4, 8);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}