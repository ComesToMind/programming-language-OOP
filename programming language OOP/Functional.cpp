#pragma once
#include "Functional.h"
#include <vector>
void Functional::InData(vector<int>  & tail)
{
	if (tail.size() < 2)
	{
		mIncorrectType = true;
		return;
	}

	if (tail[0] == 1 || tail[0] == 0 )
	{
		mLazyCalculations = tail[0];
		if (tail[1] == 1 || tail[1] == 0)
		{
			mType = static_cast<Functional::typification>(tail[1]);
		}
		else
		{
			mIncorrectType = true;
			return;
		}
	}
	else
	{
		mIncorrectType = true;
		return;
	}
	tail.erase(tail.begin() + 0, tail.begin() + 1);
	InCommon(tail);
};
void Functional::Out(ofstream &ofst)
{
	ofst << "It is Functional : lazy calculations = " << mLazyCalculations
		<< ", typification = ";
	if (mType == 0)
	{
		ofst << " STRICT, ";
	}
	else if (mType == 1)
	{
		ofst << " DYNAMIC, ";
	}
	OutCommon(ofst);
};