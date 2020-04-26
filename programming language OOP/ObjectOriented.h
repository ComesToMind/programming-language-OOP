#pragma once
#include "Language.h"
class ObjectOriented : public Language
{

	enum inheritance {
		SINGLE,
		MULTIPLE,
		INTERFACE
	};
	inheritance mInher;
public:
	virtual void MultiMethod(Language *other, ofstream &ofst);
	virtual void MmProc(ofstream &ofst);
	virtual void MmOop(ofstream &ofst);
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	ObjectOriented() {};
};