#include "Language.h"
#include "Procedural.h"
#include "ObjectOriented.h"
#include "Functional.h"
Language* Language::In(ifstream &ifst)
{
	int k,error1,error2;
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
		//здесь не мешало бы считать строку до конца нормальной командой 
		ifst >> error1 >> error2;
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
	ofst << " Develop year: " << mData << endl;
};

