#pragma once
#include "gameNode.h"
#include "worldMapScene.h"
#include "battleScene.h"
#include "Opening.h"
#include "SelectScene.h"
#include "stageScene.h"
#include "shopScene.h"

class playGround : public gameNode
{
private:

	gameNode* _currentScene;

public:
	virtual HRESULT init(void);		//초기화 함수
	virtual void release(void);		//메모리 관련 해제
	virtual void update(void);		//업데이트(연산)
	virtual void render(void);		//그려주는 함수

	playGround();
	~playGround();
};

