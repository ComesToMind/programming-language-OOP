﻿#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include "Procedural.h"
#include "ObjectOriented.h"
#include <ctime>
#include <vector>

#include <string>
#include "Functional.h"
Language* Language::In(ifstream &ifst)
{
	Language * lg;

	int k;
	bool flag = true;
	vector<int> tail;

	do 
	{
		ifst >> k;
		if (ifst.fail())
		{
			//Восстановили поток
			ifst.clear();
			ifst.ignore(numeric_limits<streamsize>::max(), '\n');
			flag = false;
			break;
		}
		if (k >= 0) 
		{
			tail.push_back(k);
		}
		else
		{
			ifst.ignore(numeric_limits<streamsize>::max(), '\n');
			flag = false;
			break;
			//сделать окончание ввода до конца
		}
	} while (!ifst.eof() && ifst.peek() != '\n');
	if (flag && !tail.empty())
	{
		ifst.ignore(numeric_limits<streamsize>::max(), '\n');
		switch (tail[0])
		{
		case 1:
			lg = new Procedural();
			break;
		case 2:
			lg = new ObjectOriented();
			break;
		case 3:
			lg = new Functional();
			break;
		default:
			return NULL;
		}
		tail.erase(tail.begin()+0);
		lg->inData(tail);

		if (lg->mIncorrectType)
			return NULL;
		else 
			return lg;
		
	}
	else
	{
		return NULL;
	}




	
};

void Language::inCommon(vector<int> &tail)
{
	if (tail.size() == 2)
	{

		mData = tail[0];
		mRef = tail[1];
	}
	else
	{
		mIncorrectType = true;
		return;
	}
};
void Language::outCommon(ofstream &ofst)
{
	ofst << " Develop year: " << mData << ", References:  " << mRef;
};

int Language::passedYears()
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	return (timeinfo->tm_year+1900)-mData;
};

bool Language::Compare(Language *second)
{
	if(this!= NULL && second != NULL)
	 return passedYears() < second->passedYears();
	return false;

}
void Language::outProc(ofstream &ofst)
{
	//ofst << endl;
}