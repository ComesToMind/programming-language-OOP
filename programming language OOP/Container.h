#pragma once
#include "Language.h"
class Container
{
	Container *Next;
	Language *L;
public:
	void MultiMethod(ofstream &ofst);
	void In(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	void outProc(ofstream &ofst);
	
	void Clear(); // ������� ���������� �� �����
	void Sort();
	void Swap(Container *first, Container *second);
	Container();
	~Container() { /*Clear();*/ }
};