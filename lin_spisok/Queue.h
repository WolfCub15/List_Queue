#pragma once
#include <istream>
#include <ostream>
#include"List.h"
using namespace std;

class Queue: public List {
private:
	Element *last;//указатель на конец очереди
public:
	Queue() :List() { last = nullptr;}
	Queue(const Queue &tmp);
	Queue &operator=(const Queue &tmp);
	~Queue();
	void push(int k);//добавление в очередь нового элемента
	int pop();//первый элемант
	bool empty();
	friend ostream &operator<<(ostream &out, Queue &tmp);
};

