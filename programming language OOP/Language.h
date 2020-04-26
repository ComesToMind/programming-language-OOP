#pragma once
#include <fstream>
#include <vector>
using namespace std;
class Language
{

public:
	static Language * In(ifstream &ifst);
	virtual void InData(vector<int>  & tail) = 0; // ввод
	virtual void Out(ofstream &ofst) = 0;
	virtual void outProc(ofstream &ofst);
	int passedYears();
	bool Compare(Language *second);

	void inCommon(vector<int> &tail);
	void outCommon(ofstream &ofst);

	short int getmData() {return mData;}
	int getmRef() {return mRef;}
	void setmData(short int mData) {this->mData = mData;}
	void setmRef(int mRef) {this->mRef = mRef;}
protected:
	short int mData;
	int mRef;
	bool mIncorrectType = false; 

	//протектед Language()???
};