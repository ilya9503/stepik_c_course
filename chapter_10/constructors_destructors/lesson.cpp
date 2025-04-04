/*
    Конструкторы
    При создании структуры в С++, ее поля будут принимать произвольные значения
    Чтобы этого избежать, следует использовать конструкторы объектов
    Как раз для этих целей предусмотрены специальные методы структур и классов, которые называются конструкторами:
        имя конструктора всегда должно совпадать с именем типа данных, в нашем случае с именем структуры point;
        конструктор никогда не возвращает никаких значений, поэтому возвращаемый тип не прописывается вовсе;
        конструктор может иметь произвольное число параметров;
        конструктор всегда вызывается при создании каждого нового объекта.

    Деструкторы
    Метод, который вызывается в момент уничтожения объекта.
    Такой метод называется деструктором и обладает следующим свойствами:
        имя метода называется также, как и тип данных с тильдой (‘~’) вначале;
        деструктор ничего не возвращает;
        деструктор не имеет параметров.

    Деструкторы служат для освобождения ресурсов, захваченных текущим объектом.
    Например, если бы в структуре point динамически выделялась память для какого-либо массива,
        то в деструкторе ее следовало бы освободить
*/

#include <iostream>
#include <math.h>
 
using std::cout;
using std::endl;
 
struct point {
private:
    int x, y;
    short* coords;
public:
    // конструктор объекта - инициализатор, является методом этой структуры
    point() { x = 0; y = 0; coords = (short *)malloc(2 * sizeof(short)); }
    // перегруженный конструктор, для начальных значений. Выделяем память для массива coords
    point(int x, int y) { this->x = x; this->y = y; coords = (short *)malloc(2 * sizeof(short)); }
    // деструктор, освобождаем память, выделенную под coords
    ~point()  { cout << "вызов деструктора объекта" << endl; free(coords); }  

    double length() { return sqrt(x*x + y*y); }

    void sum(const point& pt)
    {
        this->x += pt.x;
        this->y += pt.y;
    }
 
    void set_coords(int x, int y) 
    { 
        if(x < -100 || x > 100 || y < -100 || y > 100)
            return;
 
        this->x = x; 
        this->y = y; 
    }
 
    void get_coords(int& x, int& y) {x = this->x; y = this->y; }
    int get_x() { return this->x; }
    int get_y() { return this->y; }
};
 
int main()
{
    struct point pt {1, 2};
    int x, y;

    /*
        Здесь создается временный объект типа point с координатами (10; 20) и вычисляется длина радиус-вектора.
        После вычислений временный объект автоматически уничтожается (освобождается память, которую он занимал).
    */
    double res = point(10, 20).length();

    cout << pt.get_x() << " " << pt.get_y() << " " << res << endl;

    
    return 0;
}