#pragma once
#include "gameNode.h"
#include "player.h"


enum stageNum
{
	DR_O_HOUSE,
	GYM_WING,
	GYM_NORMAL,
	GYM_ICE,
	GYM_DRAGON,
	GYM_GHOST,
	GYM_BUG,
	GYM_FIGHT,
	GYM_STEEL,
	CHAMPION_ROAD
};

struct tagMap
{
	image* img;
	float x, y;
	RECT rc;
};

class stageScene : public gameNode
{
private:

	stageNum _stage;
	
	player* _player;

	/////////////////////////////////////////////// ���ڻ� �Ͽ콺 �� �̹��� 
	tagMap _drOHouse;
	tagMap _drO;
	tagMap _drOPixel;
	///////////////////////////////////////////// ���� �� �̹���
	tagMap _wingMap;
	tagMap _wingNPC;
	tagMap _wingPixel;
	///////////////////////////////////////////// �븻 �� �̹���
	tagMap _normalMap;
	tagMap _normalNPC;
	tagMap _wnormalPixel;
	///////////////////////////////////////////// ���� �� �̹���
	tagMap _iceMap;
	tagMap _iceNPC;
	tagMap _icePixel;
	///////////////////////////////////////////// �巡�� �� �̹���
	tagMap _dragonMap;
	tagMap _dragonNPC;
	tagMap _dragonPixel;
	///////////////////////////////////////////// ��Ʈ �� �̹���
	tagMap _ghostMap;
	tagMap _ghostNPC;
	tagMap _ghostPixel;
	///////////////////////////////////////////// ���� �� �̹���
	tagMap _bugMap;
	tagMap _bugNPC;
	tagMap _bugPixel;
	///////////////////////////////////////////// ���� �� �̹���
	tagMap _fightMap;
	tagMap _fightNPC;
	tagMap _fightPixel;
	///////////////////////////////////////////// ��ö �� �̹���
	tagMap _steelMap;
	tagMap _steelNPC;
	tagMap _steelPixel;
	///////////////////////////////////////////// ��õ�� �� �̹���
	tagMap _champion1Map;
	tagMap _champion2Map;
	tagMap _champion3Map;
	tagMap _champion4Map;

	tagMap _championNPC1;
	tagMap _championNPC2;
	tagMap _championNPC3;
	tagMap _championNPC4;

	tagMap _championPixel1;
	tagMap _championPixel2;
	tagMap _championPixel3;
	tagMap _championPixel4;

	




public:
	stageScene();
	~stageScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

