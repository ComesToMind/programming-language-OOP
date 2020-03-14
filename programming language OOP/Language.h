#pragma once
#include <fstream>
using namespace std;
class Language
{

public:
	static Language * In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ввод
	virtual void Out(ofstream &ofst) = 0;
	void YearsPassed(ofstream &ofst);
	void InCommon(ifstream &ifst);
	void OutCommon(ofstream &ofst);
protected:
	short int mData;
	//протекстед Language()???
};