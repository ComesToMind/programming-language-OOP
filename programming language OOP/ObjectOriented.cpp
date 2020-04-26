#include "ObjectOriented.h"
void ObjectOriented::InData(ifstream &ifst)
{
	int inh;
	ifst >> inh;
	if (inh == 0)
	{
		mInher = ObjectOriented::SINGLE;
	}
	else if (inh == 1)
	{
		mInher = ObjectOriented::MULTIPLE;
	}
	else if (inh == 2)
	{
		mInher = ObjectOriented::INTERFACE;
	}
	InCommon(ifst);
};
void ObjectOriented::Out(ofstream &ofst)
{
	if (mInher == 0)
	{
		ofst << " It is Object - Oriented: inheritance = SINGLE";
	}
	else if (mInher == 1)
	{
		ofst << " It is Object - Oriented: inheritance = MULTIPLE";
	}
	else if(mInher==2)
		ofst << " It is Object - Oriented: inheritance = INTERFACE";
	else
	{
		ofst << "Incorrect type of language!!!" << endl;
		return;
	}

	ofst << ",";
	OutCommon(ofst);

};


void ObjectOriented::MultiMethod(Language *other, ofstream &ofst)
{
	other->MmOop(ofst);
};
void ObjectOriented::MmProc(ofstream &ofst)
{
	ofst << "OOP and Procedural." << endl;

};
void ObjectOriented::MmOop(ofstream &ofst)
{
	ofst << "OOP and OOP." << endl;

};