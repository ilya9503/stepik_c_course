#include <iostream>
#include <memory>

struct object {
private:
    short data;
    object* next;
public:
        // здесь объявляйте конструктор и методы
    object(short d = 0, object* nextPtr = nullptr) : data{d}, next{nextPtr} { }
    
    object* get_next() const { return next; }
    short get_data() const { return data; }
    void set_next(object* ptr) { next = ptr; }
    void set_data(short d) { data = d; }
};

using st_unique_ptr = std::unique_ptr<object>;

void push(st_unique_ptr& top, short data)
{
    // здесь прописывайте реализацию функции push
    /*
        reset() обнулит предыдущий указатель и заменит на новый
        release() возвратит текущий (сырой) указатель и обнулит умный
    */
    top.reset(new object(data, top.release()));
}

int main(void)
{
    st_unique_ptr top;

    for(int i = 1; i <= 7; ++i)
        push(top, i);
    {
        object const *temp = top.get();
        // здесь продолжайте функцию main
        while(temp)
        {
            std::cout << temp->get_data() << ' ';
            temp = temp->get_next();
        }
    }

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}