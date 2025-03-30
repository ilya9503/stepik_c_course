#include <iostream>
#include <memory>

struct object {
    int data;
    std::shared_ptr<object> next;   // указатель на тип object
};

using shared_obj_ptr = std::shared_ptr<object>;

void push_back(shared_obj_ptr& head, shared_obj_ptr& tail, int data)
{
    // добавление в конец нового объекта односвязного списка
    shared_obj_ptr new_obj {std::make_shared<object>()};    // выделяем область памяти для нового объекта
    new_obj->data = data;
    // 1. Списке нет элементов. Добавляем 1-ый объект
    if(head->next == nullptr && tail->next == nullptr) {
        head->data = data;
        head->next = tail;
    }
    // 2. Добавляем 2-ой объект. Если объектов только 2 head и tail
    else if(head->next == tail && (tail->data != 0)) {
        head->next = new_obj;

        //tail->data = data;
        //head->next = tail;
    }
    // 3. Добавляем n-ый объект
    else {
        //shared_obj_ptr new_obj {std::make_shared<object>()};    // выделяем область памяти для нового объекта
        new_obj->data = data;   // заносим данные в новый объект
        //new_obj->next = tail;
        head->next = tail;
        tail.swap(new_obj);     // меняем местами tail и new_obj
        tail->next = new_obj;   // бывший tail теперь ссылается на new_obj
    }

/*
    // Если в списке один элемент, то head и tail ссылаются на один и тот же объект
    // tail -> nullptr. сделать чтобы tail ссылался на новый объект. А новый объект на nullptr
    shared_obj_ptr new_obj {std::make_shared<object>()};    // выделяем область памяти для нового объекта
    new_obj->data = data;
    new_obj->next = nullptr;

    // Если в списке один элемент, то head и tail ссылаются на один и тот же объект
    if(head->next == nullptr && tail->next == nullptr) {
        //tail = new_obj;
        head = new_obj;
        tail->next = head;
        tail->data = head->data;
        head->next = tail;
        //tail->next = new_obj;
    }
    else {
        tail.swap(new_obj);
    
    }
*/
}

void pop_front(shared_obj_ptr& head, shared_obj_ptr& tail) {
    // удаление первого объекта из односвязного списка
    // Если в списке отсутствуют элементы, то head и tail должны быть равны nullptr
    //shared_obj_ptr temp_obj {std::make_shared<object>()};
    //temp_obj = head->next;
    if(!head->next)
        return;
    if(head->next == tail->next) {
        head->next = tail->next = nullptr;
        head.reset();
        tail.reset();
        return;
    }
    head.reset(head->next.get());
}

void show(const shared_obj_ptr& head)
{
    // отображение поля data объектов односвязного списка по порядку (от head до tail) в одну строчку через пробел
    std::cout << head->data << " ";
    object* temp_obj = head->next.get();
    std::cout << temp_obj->data << " ";
    //shared_obj_ptr temp_obj {head};
    //temp_obj.reset(temp_obj->next.get());
    //std::cout << temp_obj->data << " ";
/*
    while(temp_obj->next) {
        std::cout << temp_obj->data << " ";
        if(temp_obj->next)
            temp_obj.reset(temp_obj->next.get());
    }
*/

}

int main(void)
{
    // здесь продолжайте функцию main
    shared_obj_ptr head {std::make_shared<object>()};       // выделяем область памяти для объекта head
    shared_obj_ptr tail {std::make_shared<object>()};       // выделяем область памяти для объекта tail

    push_back(head, tail, 1);
    push_back(head, tail, 2);
    push_back(head, tail, 3);
    push_back(head, tail, 4);

    show(head);

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}