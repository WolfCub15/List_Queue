#pragma once
#include"Element.h"

class List {
protected:
	Element* first;//��������� �� ������ ����� ������
public:
	List();
	List &operator= (const List & tmp);
	List(const List & tmp);
	~List();
};

