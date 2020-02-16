#pragma once
#include"Element.h"

class List {
protected:
	Element* first;//указатель на первое звено списка
public:
	List();
	List &operator= (const List & tmp);
	List(const List & tmp);
	~List();
};

