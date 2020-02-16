#include "Queue.h"

Queue::Queue(const Queue &tmp) {
	if (tmp.first==nullptr) {
		first = nullptr;
		last = nullptr;
	}
	else{
		first = new Element(*(tmp.first));
		last = first;
		Element *curr = tmp.first->get_next();
		while (curr != nullptr) {
			Element * copy_curr = new Element(*(curr));
			last->set_next(copy_curr);
			last = last->get_next();
			curr = curr->get_next();
		}
	}
}

Queue & Queue::operator=(const Queue & tmp) {
	if (this == &tmp) return *this;
	if (tmp.first == nullptr) return *this;

	delete first;
	delete last;
	if (tmp.first == nullptr) first = nullptr;
	if (tmp.last == nullptr)last = nullptr;
	else {
		first = new Element(*(tmp.first));
		Element * curr = tmp.first->get_next();
		Element * Last = first;
		while (curr != nullptr) {
			Element * copy_curr = new Element(*(curr));
			Last->set_next(copy_curr);
			Last = Last->get_next();
			curr = curr->get_next();
		}
	}
	return *this;
}

Queue::~Queue() {
	delete first;
	first = nullptr;
	last = nullptr;
}

void Queue::push(int k) {
	Element *tmp = new Element(k);//выделение памяти для нового звена 
	if (first == nullptr) {//если список пуст
		first = tmp;
		last = tmp;
	}
	else {//если список не пуст
		last->set_next(tmp);
		last = last->get_next();
	}
}

int Queue::pop() {
	if (first == nullptr) return 0;
	else if (first == last) {
		int n = first->get_info();
		delete first;
		first = nullptr;
		last = nullptr;
		return n;
	}
	else {//если список не пуст
		int n = first->get_info();
		Element *tmp = new Element(*(first));//обращаемся к началу списка
		first = first->get_next();//сдвиг начала списка
		tmp->set_next(nullptr);
		delete tmp;//освобождение памяти от предыдущего звена списка
		return n;
	}
}

bool Queue::empty() {
	return first == nullptr;
}

ostream & operator<<(ostream & out, Queue & tmp) {
	while (tmp.last != nullptr) {
		out << tmp.pop() << " ";
	}
	return out;
}
