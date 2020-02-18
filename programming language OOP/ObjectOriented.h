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
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	ObjectOriented() {};
};