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
	void Clear(); // ������� ���������� �� �����
	Container();
	~Container() { /*Clear();*/ }
};