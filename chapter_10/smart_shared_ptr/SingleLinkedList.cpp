#include <iostream>
#include <memory>

struct object {
    int data;
    std::shared_ptr<object> next;
};

using shared_obj_ptr = std::shared_ptr<object>;

void push_back(shared_obj_ptr& head, shared_obj_ptr& tail, int data) {
    // добавление в конец нового объекта односвязного списка
    shared_obj_ptr new_node {std::make_shared<object>()};    // выделяем область памяти для нового объекта
    new_node->data = data;
    
    if (!head) {    // Если head=nullptr, то head и tail ссылаются на новый узел
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

void pop_front(shared_obj_ptr& head, shared_obj_ptr& tail) {
    // удаление первого объекта из односвязного списка
    if (!head) return; // Список пуст
    
    head = head->next; // Удаление первого элемента
    
    if (!head) tail = nullptr; // Если список стал пустым
}

void show(const shared_obj_ptr& head) {
    // отображение поля data объектов односвязного списка по порядку (от head до tail) в одну строчку через пробел
    auto current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    shared_obj_ptr head = nullptr;      // создаем пустой указатель на head
    shared_obj_ptr tail = nullptr;      // создаем пустой указатель на tail
    
    push_back(head, tail, 1);
    push_back(head, tail, 2);
    push_back(head, tail, 3);
    push_back(head, tail, 4);

    //pop_front(head, tail);
    
    show(head); // Ожидаемый вывод: 1 2 3 4

    //__ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    
    return 0;
}
