#pragma once
#include "Language.h"
class Procedural : public Language
{
	int mAbstractDT;
public:
	void InData(ifstream &ifst); // ввод
	void Out(ofstream &ofst); // вывод
	Procedural() {} // создание без инициализации.
};