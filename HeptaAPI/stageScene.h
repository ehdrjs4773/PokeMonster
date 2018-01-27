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

	/////////////////////////////////////////////// 오박사 하우스 씬 이미지 
	tagMap _drOHouse;
	tagMap _drO;
	tagMap _drOPixel;
	///////////////////////////////////////////// 비행 씬 이미지
	tagMap _wingMap;
	tagMap _wingNPC;
	tagMap _wingPixel;
	///////////////////////////////////////////// 노말 씬 이미지
	tagMap _normalMap;
	tagMap _normalNPC;
	tagMap _wnormalPixel;
	///////////////////////////////////////////// 얼음 씬 이미지
	tagMap _iceMap;
	tagMap _iceNPC;
	tagMap _icePixel;
	///////////////////////////////////////////// 드래곤 씬 이미지
	tagMap _dragonMap;
	tagMap _dragonNPC;
	tagMap _dragonPixel;
	///////////////////////////////////////////// 고스트 씬 이미지
	tagMap _ghostMap;
	tagMap _ghostNPC;
	tagMap _ghostPixel;
	///////////////////////////////////////////// 벌레 씬 이미지
	tagMap _bugMap;
	tagMap _bugNPC;
	tagMap _bugPixel;
	///////////////////////////////////////////// 격투 씬 이미지
	tagMap _fightMap;
	tagMap _fightNPC;
	tagMap _fightPixel;
	///////////////////////////////////////////// 강철 씬 이미지
	tagMap _steelMap;
	tagMap _steelNPC;
	tagMap _steelPixel;
	///////////////////////////////////////////// 사천왕 씬 이미지
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

