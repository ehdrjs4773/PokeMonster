#pragma once
#include "gameNode.h"
#include "player.h"


enum stageNum
{
	DR_O_HOUSE,
	GYM_WING,
	GYM_NOMAL,
	GYM_ICE,
	GYM_DRAGON,
	GYM_GHOST,
	GYM_BUG,
	GYM_FIGHT,
	GYM_STEEL,
	CHAMPION_ROAD
};

class stageScene : public gameNode
{
private:

	stageNum _stage;
	
	player* _player;

	//오박사 하우스 씬 이미지 
	image* _drO;			//오박사 NPC 이미지
	image* _drOHouse;
	image* _drOHousePixel;

	float _x, _y;			//오박사 x,y 좌표
	RECT _drRc;				//오박사 그려줄 렉트
	
	




public:
	stageScene();
	~stageScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

