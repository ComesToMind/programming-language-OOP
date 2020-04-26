#pragma once
#include "Language.h"

class Procedural : public Language
{
	int mAbstractDT;
public:
	void InData(vector<int>  & tail); // ввод
	void Out(ofstream &ofst); // вывод
	void OutProc(ofstream &ofst);
	Procedural() {} // создание без инициализации.
	
	 int GetmAbstractDT() { return mAbstractDT; }	
	void SetmAbstractDT(int mAbstractDT) {this->mAbstractDT = mAbstractDT;}
};