#pragma once
#include "Language.h"
class Container
{
	Container *Next;
	Language *L;
public:
	void MultiMethod(ofstream &ofst);
	void In(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	void Clear(); // очистка контейнера от фигур
	Container();
	~Container() { /*Clear();*/ }
};