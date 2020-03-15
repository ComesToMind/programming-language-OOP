#pragma once
#include "Language.h"
class Container
{
	Container *Next;
	Language *L;
public:
	void In(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	void OutProc(ofstream &ofst);
	void Clear(); // очистка контейнера от фигур
	Container();
	~Container() { /*Clear();*/ }
};