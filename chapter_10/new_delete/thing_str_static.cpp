#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::cin;

enum{max_len=50};

// здесь объявляйте структуру

struct thing {
    unsigned long id{0};       // идентификатор
    char name[max_len];        // название
    unsigned int price;        // цена
    double weight;             // вес
    
    thing(const char* name="", unsigned int price=0, double weight=0.0)
    {
        strncpy(this->name, name, max_len);
        this->price = price;
        this->weight = weight;
        static unsigned long temp_id{0};    // создается 1 раз
        temp_id++;
        this->id = temp_id;
        //cout << "Вызов конструктора thing, id = " << this->id << endl;
    }
    ~thing() { /* cout << "Вызов деструктора thing" << endl; */ }
};

int main(void)
{
    char name[max_len]{0};
    unsigned int price{0};
    double weight{0};
    cin >> name >> price >> weight;

    thing th_1;
    thing* ptr_th = new thing(name, price, weight);
    cout << ptr_th->price << endl;
    delete ptr_th;

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}