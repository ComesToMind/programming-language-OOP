#include "Procedural.h"
#include <vector>
void Procedural::inData(vector<int>  & tail)
{
	if (tail.size() < 1)
	{
		mIncorrectType = true;
		return;
	}

	if (tail[0] == 1 ||  tail[0] == 0)
	{
		mAbstractDT = tail[0];
	}
	else
	{
		mIncorrectType = true;
		return;
	}
	tail.erase(tail.begin()+0);
	inCommon(tail);
};
void Procedural::Out(ofstream &ofst)
{
	if (mAbstractDT == -1);
	ofst << "It is Procedural : abstrat data type = " <<  mAbstractDT
		<< ", ";
	outCommon(ofst);
};

void Procedural::outProc(ofstream &ofst)
{
	Out(ofst);
};