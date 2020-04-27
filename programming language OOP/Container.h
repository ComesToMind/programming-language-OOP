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
	void outProc(ofstream &ofst);
	
	void Clear(); // очистка контейнера от фигур
	void Sort();
	void Swap(Container *first, Container *second);
	Container();
	~Container() { /*Clear();*/ }
};