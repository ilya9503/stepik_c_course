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

using st_unique_ptr = std::unique_ptr<object>;

// Мой вариант
/*
void push(st_unique_ptr& top, short data)
{
    // здесь прописывайте реализацию функции push
    if(data == 1)
        top = std::make_unique<object>(data);   // создаем новый объект с данными data. Указатель top указывает nullptr
    else {
        object* temp = top.get();               // получаем указатель предыдущего объекта стека
        top = std::make_unique<object>(data);   // создаем новый объект с данными data. Указатель top указывает nullptr
        top->set_next(temp);                    // присваиваем новому объекту указатель предыдущего
    }
}
*/
// Удачный вариант
void push(st_unique_ptr& top, short data)
{
    if(top == nullptr){
        top = std::make_unique<object>(data);
        return;        
    }
    object* obj = new object(data);
    obj->set_next(top.release());
    top.reset(obj);
}

int main(void)
{
    st_unique_ptr top;

    for(int i = 1; i <= 7; ++i)
        push(top, i);

    // здесь продолжайте функцию main
    std::cout << top->get_data() << " ";    // данные 7-ого элемента стека
    object* temp = top->get_next();         // адрес 6-ого элемента
    std::cout << temp->get_data() << " ";   // данные 6-ого элемента

    while (temp->get_next() != nullptr) {
        if(temp->get_next() != nullptr) {
            temp = temp->get_next();
            std::cout << temp->get_data() << " ";
        }
    }

    std::cout << std::endl;
                                  
    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}