#pragma once
#include <fstream>
#include <vector>
using namespace std;
class Language
{

public:
	static Language * In(ifstream &ifst);
	virtual void inData(vector<int>  & tail) = 0; // ����
	virtual void Out(ofstream &ofst) = 0;
	virtual void outProc(ofstream &ofst);
	int passedYears();
	bool Compare(Language *second);

	virtual void MultiMethod(Language *other, ofstream &ofst) = 0;
	virtual void MmProc(ofstream &ofst) = 0;
	virtual void MmOop(ofstream &ofst) = 0;
	virtual void MmFunc(ofstream &ofst)= 0;

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

	//��������� Language()???
};