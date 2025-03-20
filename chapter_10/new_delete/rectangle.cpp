/*
    Проверка попадания точки в границы прямоугольника
*/
#include <iostream>

// здесь объявляйте структуру
struct rectangle {
private:
    int x0, y0, x1, y1;
public:
    rectangle(int x0=0, int y0=0, int x1=0, int y1=0)
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;
    }
    ~rectangle() {}
    // проверяет попадание точки (x, y) внутрь прямоугольника; true - если попадает (включая границы), false - если не попадает
    bool is_in_rect(int x, int y)
    {
        return x >= this->x0 && x <= this->x1 && y >= this->y0 && y <= this->y1;
    }
    // задает новые координаты прямоугольника
    void set_coords(int x0, int y0, int x1, int y1)
    {
        this->x0 = x0;
        this->y0 = y0;
        this->x1 = x1;
        this->y1 = y1;        
    }
    // возвращает текущие координаты прямоугольника
    void get_coords(int& x0, int& y0, int& x1, int& y1)
    {
        x0 = this->x0;
        y0 = this->y0;
        x1 = this->x1;
        y1 = this->y1;
    } 
};


int main()
{
    rectangle* ptr_r = new rectangle(-5, 4, 8, 32);
    int x, y;
    std::cin >> x >> y;
    std::cout << (ptr_r->is_in_rect(x, y) ? "yes" : "no") << std::endl;
    delete ptr_r;
    return 0;
}