#pragma once
#include "gameNode.h"
#include "worldMapScene.h"
#include "battleScene.h"
#include "Opening.h"
#include "SelectScene.h"
#include "shopScene.h"
#include "inventory.h"
#include "UI.h"
#include "MonsterBack.h"
#include "Ending.h"
//--------수테이지------

#include "drOHouse.h"	// 정보번호 0
#include "steelMap.h"	// 정보번호 1
#include "fighterMap.h"	// 정보번호 2
#include "ghostMap.h"	// 정보번호 3
#include "normalMap.h"	// 정보번호 4
#include "dragonMap.h"	// 정보번호 5
#include "bugMap.h"		// 정보번호 6
#include "flyMap.h"		// 정보번호 7
#include "iceMap.h"		// 정보번호 8
#include "guardian1.h"	// 정보번호 9
#include "guardian2.h"	// 정보번호 10
#include "guardian3.h"	// 정보번호 11
#include "guardian4.h"	// 정보번호 12
#include "champion.h"	// 정보번호 13

#include "player.h"


class playGround : public gameNode
{
private:
	player* _player;
	gameNode* _currentScene;

public:
	virtual HRESULT init(void);		//초기화 함수
	virtual void release(void);		//메모리 관련 해제
	virtual void update(void);		//업데이트(연산)
	virtual void render(void);		//그려주는 함수

	void imageInit();

	playGround();
	~playGround();
};

