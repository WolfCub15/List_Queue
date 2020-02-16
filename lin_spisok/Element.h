#pragma once
class Element {//�����
private:
	int info;//�������� �������� (�������� ������)
	Element* next;//��������� �� ��������� �������
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

