/*
    Отличия массива от односвязного списка:
    В отличие от классического массива, где данные в памяти расположены строго последовательно, в односвязном списке,
        наоборот, данные расположены хаотично и связывание узлов списка происходит посредством ссылок.
    За счёт этой особенности в односвязный список можно добавлять произвольное число элементов, однако,
        доступ будет осуществляться только последовательно.
*/

#include <iostream>

enum { max_nodes=10 };

// Узел односвязного списка
struct Node {       
public:
	double data;    // Данные
	Node* next;     // Указатель на следующий узел списка (у крайнего NULL)
public:
	Node(double data) {
		this->data = data;
		this->next = NULL;
	}
};

// Односвязный список
struct OneLinkedList {  
public:
    // Указатели на начальный(head) и конечный(tail) эл-ты списка
	Node* head, * tail;
    int counter{0}; // Количество созданных узлов (объектов)
public:
    // Конструктор инициализирует список пустым
	OneLinkedList() {   
                        // 
		this->head = this->tail = NULL;
	}

    // Деструктор удаляет все узлы списка
	~OneLinkedList() {
		while (head != NULL) pop_front();
	}

    // Удаление 1-ого элемента
	void pop_front() {              
		if (head == NULL) return;   // Если список пуст — ничего не делаем
		if (head == tail) {         // Если один элемент
			delete tail;
			head = tail = NULL;
			return;
		}

		Node* node = head;
		head = node->next;          // Сдвигаем head на следующий узел
		delete node;

        counter--;
	}

    // Создаем и добавляем новый узел в конец
	void push_back(double data) {
        if(counter >= max_nodes)                 // Превышение счетчика
            return;

		Node* node = new Node(data);
		if (head == NULL) head = node;          // Если список пуст — новый узел становится head
		if (tail != NULL) tail->next = node;    // Старый tail ссылается на новый узел
		tail = node;

        counter++;
	}

    // Создаем и добавляем новый узел в начало
	void push_front(double data) {
        if(counter >= max_nodes)                 // Превышение счетчика
            return;

		Node* node = new Node(data);
		node->next = head;                  // Новый узел указывает на старый head
		head = node;                        // Новый узел становится head
		if (tail == NULL) tail = node;      // Если был пустой список, обновляем tail

        counter++;
	}

    // Удаление последнего элемента
	void pop_back() {
		if (tail == NULL) return;
		if (head == tail) {
			delete tail;
			head = tail = NULL;
			return;
		}

		Node* node = head;
		for (; node->next != tail; node = node->next);

		node->next = NULL;
		delete tail;
		tail = node;

        counter--;
	}

    // Получение узла по индексу
	Node* getAt(int k) {
    /*
        Перемещается от head на k позиций.
        Если k больше количества узлов — возвращает NULL.
    */
		if (k < 0 || counter >= max_nodes) return NULL; // Превышение счетчика      
		Node* node = head;
		int n = 0;
		while (node && n != k && node->next) {
			node = node->next;
			n++;
		}

		return (n == k) ? node : NULL;
	}

    // Вставка по индексу
	void insert(int k, double data) {
    /*
        Находит узел по индексу k.
        Вставляет новый узел между left и right.
        Если вставка в конец, обновляет tail.
    */             
        Node* left = getAt(k);
        
		if (left == NULL || counter >= max_nodes) return;  // Превышение счетчика  

		Node* right = left->next;
		Node* node = new Node(data);

		left->next = node;
		node->next = right;
		if (right == NULL) tail = node;

        counter++;
	}

    // Удаление по индексу
	void erase(int k) {
    /*
        Если k == 0, вызывает pop_front().
        Находит узел перед удаляемым (left).
        Переподключает left->next, удаляет node.
        Если удаляется tail, обновляет tail.
    */
		if (k < 0) return;
		if (k == 0) {
			pop_front();
			return;
		}

		Node* left = getAt(k - 1);
		Node* node = left->next;
		if (node == NULL) return;

		Node* right = node->next;
		left->next = right;
		if (node == tail) tail = left;
		delete node;

        counter--;
	}
};

int main(void)
{
	OneLinkedList lst;
/*
	lst.push_front(1);                      // Создаем и добавляем узел в начало списка
	lst.push_back(2);                       // Создаем и добавляем узел в конец списка
                                            // [1] → [2]  (head = 1, tail = 2)
	
	Node* n = lst.getAt(0);                 // Получаем узел по индексу 0 (head)
	double d = (n != NULL) ? n->data : 0;   // Записываем значение данные узла с индексом 0 в d
	std::cout << d << std::endl;

    lst.erase(0);       
	lst.erase(1);       // Удаляем элемент с индексом 1.   [1]  (head = tail = 1)
*/
//	lst.insert(0, 5);   // Вставляем элемент 5 в начало.   [5] → [1]  (head = 5, tail = 1)
//	lst.insert(0, 2);   // Вставляем элемент 2 в начало.   [2] → [5] → [1]  (head = 2, tail = 1)
lst.push_back(1);
lst.push_back(2);
lst.push_back(3);
lst.push_back(4);
lst.push_back(5);
lst.push_back(6);
lst.push_back(7);
lst.push_back(8);
lst.push_back(9);
lst.push_back(10);
lst.insert(0, 1.1);
lst.insert(0, 1.2);



    // От head до tail(NULL)
	for (Node* node = lst.head; node != NULL; node = node->next) {
		std::cout << node->data << " ";
	}

	return 0;
}