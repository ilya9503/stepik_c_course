/*
    Отличия массива от односвязного списка:
    В отличие от классического массива, где данные в памяти расположены строго последовательно, в односвязном списке,
        наоборот, данные расположены хаотично и связывание узлов списка происходит посредством ссылок.
    За счёт этой особенности в односвязный список можно добавлять произвольное число элементов, однако,
        доступ будет осуществляться только последовательно.
*/

#include <iostream>

enum { max_nodes=10 };

typedef struct  {
	char author[50];	// автор
	char title[100];	// заголовок
	short year;		    // год издания
} BOOK;

// Узел односвязного списка
struct Node {       
public:
	BOOK data;    // Данные
	Node* next;     // Указатель на следующий узел списка (у крайнего NULL)
public:
	Node(BOOK data) {
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
	void push_back(BOOK data) {
        if(counter >= max_nodes)                 // Превышение счетчика
            return;

		Node* node = new Node(data);
		if (head == NULL) head = node;          // Если список пуст — новый узел становится head
		if (tail != NULL) tail->next = node;    // Старый tail ссылается на новый узел
		tail = node;

        counter++;
	}

    // Создаем и добавляем новый узел в начало
	void push_front(BOOK data) {
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
	void insert(int k, BOOK data) {
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
    using namespace std;
    // здесь пишите программу
    OneLinkedList lib;
	
    BOOK books[] {	
		{.author{"Пушкин А.С."}, .title{"Пиковая дама"}, .year{2007}},
		{.author{"Тургенев И.С."}, .title{"Муму"}, .year{2011}},
		{.author{"Толстой А.Н."}, .title{"Аэлита"}, .year{1995}},
		{.author{"Балакирев С.М."}, .title{"Моя жизнь, мои достижения"}, .year{2045}}
	};

    lib.push_back(books[0]);
    lib.push_back(books[1]);
    lib.push_back(books[2]);
    lib.push_back(books[3]);

    //__assertion_tests(lib);    // эту строчку не убирать (должна стоять перед return 0)
    
    return 0;
}