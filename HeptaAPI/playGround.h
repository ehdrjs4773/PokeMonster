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
//--------��������------

#include "drOHouse.h"	// ������ȣ 0
#include "steelMap.h"	// ������ȣ 1
#include "fighterMap.h"	// ������ȣ 2
#include "ghostMap.h"	// ������ȣ 3
#include "normalMap.h"	// ������ȣ 4
#include "dragonMap.h"	// ������ȣ 5
#include "bugMap.h"		// ������ȣ 6
#include "flyMap.h"		// ������ȣ 7
#include "iceMap.h"		// ������ȣ 8
#include "guardian1.h"	// ������ȣ 9
#include "guardian2.h"	// ������ȣ 10
#include "guardian3.h"	// ������ȣ 11
#include "guardian4.h"	// ������ȣ 12
#include "champion.h"	// ������ȣ 13

#include "player.h"


class playGround : public gameNode
{
private:
	player* _player;
	gameNode* _currentScene;

public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�

	void imageInit();

	playGround();
	~playGround();
};

