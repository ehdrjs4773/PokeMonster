#include "stdafx.h"
#include "database.h"
#include "pokemon.h"
#include "stageManager.h"


database::database()
{
}


database::~database()
{

}

HRESULT database::init()
{
	this->loadDatabasePokemon(".\\textData\\pokemonFinish.txt");
	this->loadDatabaseSkill(".\\textData\\pokemon_skill.txt");

	for (int i = 0; i < 8; ++i)
		_isStageClear[i] = false;

	return S_OK;
}

void database::update()
{
	for (int i = 0; i < 8; ++i)
	{
		string temp = "스테이지" + (i + 1);
		stageManager* tempScene = (stageManager*)SCENEMANAGER->findScene(temp);
		_isStageClear[i] = tempScene->getIsWin();
	}
}

void database::release()
{

}


void database::loadDatabasePokemon(string name)
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
	
		if (i == count + 1)
		{
			mIter->second->name = vTemp[i].c_str();
			string temp = mIter->second->name + "s";
			string filePath = ".\\bmps\\MonsterBag\\" + temp + ".bmp";
			IMAGEMANAGER->addFrameImage(temp, filePath.c_str(), 40 * 2, 40, 2, 1, false, true, MAGENTA);
		}
		else if (i == count + 2) mIter->second->hp = atoi(vTemp[i].c_str());
		else if (i == count + 3) mIter->second->atk = atoi(vTemp[i].c_str());
		else if (i == count + 4) mIter->second->def = atoi(vTemp[i].c_str());
		else if (i == count + 5) mIter->second->speed = atoi(vTemp[i].c_str());
		else if (i == count + 6) mIter->second->special = atoi(vTemp[i].c_str());
		else if (i == count + 7) mIter->second->element = atoi(vTemp[i].c_str());
	}
	
	vTemp.clear();
}

void database::loadDatabaseSkill(string name)
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
			skills* em = new skills;
			str = vTemp[i + 1];

			_mTotalSkill.insert(pair<string, skills*>(vTemp[i + 1], em));

			if (i != 0) count += 7;
			continue;
		}

		map<string, skills*>::iterator mIter = _mTotalSkill.find(str);

		if (i == count + 1) mIter->second->name = vTemp[i].c_str();
		else if (i == count + 2) mIter->second->element = atoi(vTemp[i].c_str());
		else if (i == count + 3) mIter->second->type = atoi(vTemp[i].c_str());
		else if (i == count + 4) mIter->second->power = atoi(vTemp[i].c_str());
		else if (i == count + 5) mIter->second->acc = atoi(vTemp[i].c_str());
		else if (i == count + 6) mIter->second->pp = atoi(vTemp[i].c_str());
	}

	vTemp.clear();
}