#pragma once
#include "Language.h"
class ObjectOriented : public Language
{
public:
	enum inheritance {
		SINGLE,
		MULTIPLE,
		INTERFACE
	};
	void inData(vector<int>  & tail); // ввод
	void Out(ofstream &ofst); // вывод
	 void MultiMethod(Language *other, ofstream &ofst);
	 void MmProc(ofstream &ofst);
	 void MmOop(ofstream &ofst);
	 void MmFunc(ofstream &ofst);

	ObjectOriented() {};
	inheritance getmInher() { return mInher; }
	void setmInher(inheritance mInher) { this->mInher = mInher; }
private:
	inheritance mInher;
};