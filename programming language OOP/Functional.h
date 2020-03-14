#pragma once
#include "Language.h"
class Functional : public Language
{
public:
	Functional() {/**/ }
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
private:
	unsigned short int mLazyCalculations;
	enum typification
	{
		STRICT,
		DYNAMIC
	} mType;
};