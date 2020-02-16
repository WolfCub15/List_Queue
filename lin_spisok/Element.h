#pragma once
class Element {//звено
private:
	int info;//значение элемента (хранимые данные)
	Element* next;//указатель на следующий элемент
public:
	Element();
	Element(int _info = 0);
	Element(const Element & tmp);
	~Element();
	Element &operator=(const Element & tmp);
	int get_info();
	Element* get_next();
	void set_info(const int & k);
	void set_next(Element *k);
};

