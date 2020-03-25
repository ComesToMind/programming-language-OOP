#include "Language.h"
#include "Procedural.h"
#include "ObjectOriented.h"
#include <string>
#include "Functional.h"
Language* Language::In(ifstream &ifst)
{
	int k,error1,error2,error3;
	char error[255];
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
	case 3: 
		lg = new Functional();
		break;
	default:
		char b;
		ifst >> b;
		//читатем до конца строки
		while (!ifst.eof() && ifst.peek()!='\n')
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
	ifst >> mData >> mRef;
};
void Language::OutCommon(ofstream &ofst)
{
	ofst << " Develop year: " << mData << ", References:  " << mRef << endl;
};

