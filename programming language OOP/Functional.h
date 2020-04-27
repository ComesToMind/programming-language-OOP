#pragma once
#include "Language.h"
class Functional : public Language
{
public:
	enum typification
	{
		STRICT,
		DYNAMIC
	};
	Functional() {/**/ }
	void inData(vector<int>  & tail); // ввод
	void Out(ofstream &ofst); // вывод

	 void MultiMethod(Language *other, ofstream &ofst);
	 void MmProc(ofstream &ofst);
	 void MmOop(ofstream &ofst);
	 void MmFunc(ofstream &ofst);

	typification getmType() { return mType; };
	void setmType(typification mType) { this->mType= mType; };
	unsigned short int getmLazyCalculations() { return mLazyCalculations; }
	void setmLazyCalculations(unsigned short int mLazyCalculations) { this->mLazyCalculations = mLazyCalculations; }

private:
	unsigned short int mLazyCalculations;
	typification mType;
	

};