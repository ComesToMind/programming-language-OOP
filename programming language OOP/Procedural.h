#pragma once
#include "Language.h"
class Procedural : public Language
{
	int mAbstractDT;
public:
	virtual void MultiMethod(Language *other, ofstream &ofst);
	virtual void MmProc(ofstream &ofst);
	virtual void MmOop(ofstream &ofst);
	void InData(ifstream &ifst); // ����
	void Out(ofstream &ofst); // �����
	Procedural() {} // �������� ��� �������������.
};