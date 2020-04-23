#pragma once
#include <fstream>
using namespace std;
class Language
{

public:
	static Language * In(ifstream &ifst);
	virtual void InData(ifstream &ifst) = 0; // ввод
	virtual void Out(ofstream &ofst) = 0;
	virtual void OutProc(ofstream &ofst);
	int YearsPassed();
	bool Compare(Language &second);
	void InCommon(ifstream &ifst);
	void OutCommon(ofstream &ofst);
	short int GetmData() {return mData;}
	int GetmRef() {return mRef;}
	void SetmData(short int mData) {this->mData = mData;}
	void SetmRef(int mRef) {this->mRef = mRef;}
protected:
	short int mData;
	int mRef;

	//протектед Language()???
};