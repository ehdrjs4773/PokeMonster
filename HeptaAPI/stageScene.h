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

	//���ڻ� �Ͽ콺 �� �̹��� 
	image* _drO;			//���ڻ� NPC �̹���
	image* _drOHouse;
	image* _drOHousePixel;

	float _x, _y;			//���ڻ� x,y ��ǥ
	RECT _drRc;				//���ڻ� �׷��� ��Ʈ
	
	




public:
	stageScene();
	~stageScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

