#include "Procedural.h"
#include <vector>
void Procedural::InData(vector<int>  & tail)
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
	InCommon(tail);
};
void Procedural::Out(ofstream &ofst)
{
	if (mAbstractDT == -1);
	ofst << "It is Procedural : abstrat data type = " <<  mAbstractDT
		<< ", ";
	OutCommon(ofst);
};

void Procedural::OutProc(ofstream &ofst)
{
	Out(ofst);
};