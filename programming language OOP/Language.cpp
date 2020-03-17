#define _CRT_SECURE_NO_WARNINGS
#include "Language.h"
#include "Procedural.h"
#include "ObjectOriented.h"
#include <ctime>

Language* Language::In(ifstream &ifst)
{
	int k;
	Language * lg;
	ifst >> k;
	switch (k)
	{
	case 1:
		lg = new Procedural();
		break;
	case 2:
		lg = new ObjectOriented();
		break;
	default:
		char b;
		ifst >> b;
		//÷èòàòåì äî êîíöà ñòðîêè
		while (!ifst.eof() && ifst.peek() != '\n')
		{
			ifst >> b;
			//b=?
		}
		return NULL;
	}
	lg->InData(ifst);
	//lg->InCommon(ifst);
	return lg;
};

void Language::InCommon(ifstream &ifst)
{
	ifst >> mData;
};
void Language::OutCommon(ofstream &ofst)
{
	ofst << "Год создания: " << mData << endl;
};

int Language::YearsPassed()
{
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	return (timeinfo->tm_year+1900)-mData;
};

bool Language::Compare(Language &second)
{
	 return YearsPassed() < second.YearsPassed();

}