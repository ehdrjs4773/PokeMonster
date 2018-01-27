#include "stdafx.h"
#include "database.h"
#include "pokemon.h"


database::database()
{
}


database::~database()
{

}

HRESULT database::init()
{
	this->loadDatabase(".\\textData\\pokemonTest.txt");

	return S_OK;
}

void database::release()
{

}


void database::loadDatabase(string name)
{
	arrElements vTemp;
	vTemp = TXTDATA->txtLoad(name.c_str());
	
	string str;
	int count = 0;
	
	for (int i = 0; i < vTemp.size(); ++i)
	{
		//칸막이를 찾았으면
		if (vTemp[i] == "|")
		{
			elements* em = new elements;
			str = vTemp[i + 1];
	
			_mTotalElement.insert(pair<string, elements*>(vTemp[i + 1], em));
	
			if (i != 0) count += 8;
			continue;
		}
	
		iterElement mIter = _mTotalElement.find(str);
	
		if (i == count + 1) mIter->second->name = vTemp[i].c_str();
		else if (i == count + 2) mIter->second->hp = atoi(vTemp[i].c_str());
		else if (i == count + 3) mIter->second->atk = atoi(vTemp[i].c_str());
		else if (i == count + 4) mIter->second->def = atoi(vTemp[i].c_str());
		else if (i == count + 5) mIter->second->speed = atoi(vTemp[i].c_str());
		else if (i == count + 6) mIter->second->special = atoi(vTemp[i].c_str());
		else if (i == count + 7) mIter->second->element = atoi(vTemp[i].c_str());
	}
	
	vTemp.clear();
}
