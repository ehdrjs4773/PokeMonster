#pragma once
#include "gameNode.h"

struct PokeInfo
{
	RECT rc;
	RECT PokeImageRc;
	POINT NameTxt;
	POINT HpTxt;
	image* RectImage;
	image* PoketImage;
	int HP;
	int Level;
	bool Catch; 
	string strKey;
};



class MonsterBack : public gameNode
{
private :
	RECT _CancleRc;


	PokeInfo _PokeInfo[6];


public:
	MonsterBack();
	~MonsterBack();

	virtual HRESULT init(void);
	virtual void render(void);
	virtual void update(void);
	virtual void release(void);

	int getPokeMonHp(int Num) { return _PokeInfo[Num].HP; }
	int getPokeMonLevel(int Num) { return _PokeInfo[Num].Level; }
	

};

