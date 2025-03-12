/*
    Упражнения на сеттеры и геттеры
*/

#include <iostream>
 
struct thing {
private:
    unsigned int id;
    double price;
    double weight;
public:
    unsigned get_id() { return this->id; }

    void get_data(double& price, double& weight)
    {
        price = this->price;
        weight = this->weight;
    }

    void set_data(unsigned id, double price, double weight)
    {
        this->id = id;
        this->price = price;
        this->weight = weight;
    }
};

struct point {
private:
    int x, y;
public:
    int get_x() { return this->x; }

    int get_y() { return this->y; }

    void get_coords(int& x, int& y)
    {
        x = this->x;
        y = this->y;
    }

    void set_coords(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    static point sum(point& p1, point& p2)
    {
        point temp;
        temp.x = p1.x + p2.x;   // можем обращаться к private, тк внутри структуры
        temp.y = p1.y + p2.y;
        return temp;
    }
};

 
int main()
{
    point p1, p2, res;
    int x, y, x1, y1;
    std::cin >> x >> y >> x1 >> y1;

    p1.set_coords(x, y);
    p2.set_coords(x1, y1);

    res = point::sum(p1, p2);
    std::cout << res.get_x() << " " << res.get_y() << std::endl;

    return 0;
}