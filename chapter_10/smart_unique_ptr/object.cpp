#include <iostream>
#include <memory>

struct object {
private:
    short data;
    object* next;

public:
    // здесь объявляйте конструктор и методы
    object(short d)
    {
        this->data = d;
        this->next = nullptr;
    }
    // геттер, возвращающий значение указателя next
    object* get_next()
    {
        return this->next;
    }
    // геттер, возвращающий значение поля data
    short get_data()
    {
        return this->data;
    }
    // сеттер, записывающий в указатель next значение адреса указателя ptr
    void set_next(object* ptr)
    {
        this->next = ptr;
    }
    // сеттер, записывающий в поле data значение d
    void set_data(short d)
    {
        this->data = d;
    }
};

int main(void)
{
    // здесь продолжайте функцию main
    std::unique_ptr<object> ptr, top;
    ptr = std::make_unique<object>(1);
    top = std::make_unique<object>(2);

    top->set_next(ptr.get());   // преобразует умный указатель в обычный указатель (адрес) object*

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}