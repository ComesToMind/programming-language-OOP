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
	ObjectOriented() {};
	inheritance getmInher() { return mInher; }
	void setmInher(inheritance mInher) { this->mInher = mInher; }
private:
	inheritance mInher;
};