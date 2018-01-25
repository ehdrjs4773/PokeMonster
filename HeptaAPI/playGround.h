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
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�

	playGround();
	~playGround();
};

