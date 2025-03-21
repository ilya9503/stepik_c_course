/*
    Особенности работы new и delete

    На предыдущем занятии мы с вами познакомились с новыми операторами:
        new / new [] – для выделения памяти в куче с автоматическим вызовом конструктора объекта;
        delete / delete [] – для освобождения памяти в куче с автоматическим вызовом деструктора объекта.

    В С++ при создании структуры, компилятор автоматически создает конструктор и деструктор (без параметров).
        Если конструктор и деструктор не объявлен явно программистом

    Любой тип данных языка С++ подразумевает использование этих специальных методов: конструкторов и деструктора.
        В частности, это означает, что с любым примитивным типом данных мы можем выполнять все те же самые действия, что и со структурами.


    Непосредственно после создания объекта структуры с помощью оператора new компилятор автоматически добавляет
        вызов конструктора этой структуры

    Непосредственно перед удалением объекта структуры с помощью оператора delete компилятор автоматически добавляет
        вызов деструктора этой структуры    
*/

#include <iostream>
 
using std::cout;
using std::endl;
 
struct volume {
    int width, height, depth;
    //volume() { cout << "constructor" << endl; }
};

int main(void)
{
    volume* v_1 = new volume;               // v_1 инициализируется произвольными значениями
    volume* v_2 {new volume};               // тоже самое, что new volume
    volume* v_3 = new volume();             // v_3 инициализируется нулями
    volume* v_4 {new volume{1, 2, 3}};      // V_4 инициализируется зн-ями 1, 2, 3
 
    cout << v_1->width << " " << v_1->height << " " << v_1->depth << endl;
    cout << v_3->width << " " << v_3->height << " " << v_3->depth << endl;
    cout << v_4->width << " " << v_4->height << " " << v_4->depth << endl;
 
    delete v_1;
    delete v_2;
    delete v_3;
    delete v_4;
 
    return 0;
}