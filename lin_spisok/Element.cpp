#include "Element.h"

Element::Element() {
	info = 0;
	next = nullptr;
}

Element::Element(int _info) {
	info = _info;
	next = nullptr;
}

Element::Element(const Element & tmp) {
	info = tmp.info;
	next = nullptr;
}

Element::~Element() {
	delete next;//убивает весь список!!!!!!!!!!!!!!!!
}

Element & Element::operator=(const Element & tmp) {
	if (this == &tmp) return *this;
	info = tmp.info;
	next = nullptr;
	return *this;
}

int Element::get_info() {
	return this->info;
}

Element * Element::get_next() {
	return next;
}

void Element::set_info(const int &k) {
	this->info = k;
}

void Element::set_next(Element* k) {
	this->next = k;
}
