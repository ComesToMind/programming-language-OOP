#pragma once
#include "Language.h"

class Procedural : public Language
{
	int mAbstractDT;
public:
	void inData(vector<int>  & tail); // ����
	void Out(ofstream &ofst); // �����
	void outProc(ofstream &ofst);
	Procedural() {} // �������� ��� �������������.
	
	 int getmAbstractDT() { return mAbstractDT; }	
	void setmAbstractDT(int mAbstractDT) {this->mAbstractDT = mAbstractDT;}
};