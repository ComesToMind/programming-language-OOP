#pragma once
#include "Language.h"

class Procedural : public Language
{
	int mAbstractDT;
public:
	void inData(vector<int>  & tail); // ввод
	void Out(ofstream &ofst); // вывод
	void MultiMethod(Language *other, ofstream &ofst);
	void MmProc(ofstream &ofst);
	void MmOop(ofstream &ofst);
	void MmFunc(ofstream &ofst);

	void outProc(ofstream &ofst);
	Procedural() {} // создание без инициализации.
	
	 int getmAbstractDT() { return mAbstractDT; }	
	void setmAbstractDT(int mAbstractDT) {this->mAbstractDT = mAbstractDT;}
};