#include "list.h"
#include <iostream>
#include <limits.h>
List::List() {
	first= nullptr;
	
}

List & List::operator=(const List & tmp) {
	if (this == &tmp) return *this;
	delete first;
	if (tmp.first == nullptr) first = nullptr;
	else{
		first = new Element(*(tmp.first));
		Element * curr = tmp.first->get_next();
		Element * last = first;
		while (curr != nullptr) {
			Element * copy_curr = new Element(*(curr));
			last->set_next(copy_curr);
			last = last->get_next();
			curr = curr->get_next();
		}
	}
	return *this;
}

List::List(const List & tmp) {
	if (tmp.first == nullptr) {
		first = nullptr;
	}
	else {
		first = new Element(*(tmp.first));
		Element *curr = tmp.first->get_next();
		Element *last = first;
		while (curr != nullptr) {
			Element * copy_curr = new Element(*(curr));
			last->set_next(copy_curr);
			last = last->get_next();
			curr = curr->get_next();
		}
	}
}

List::~List() {
	delete first;
}
