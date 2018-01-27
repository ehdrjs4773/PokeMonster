#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{

}


playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);

	SCENEMANAGER->addScene("월드맵씬", new worldMapScene);
	SCENEMANAGER->addScene("battleScene", new battleScene);

	SCENEMANAGER->addScene("오프닝씬", new Opening);
	SCENEMANAGER->addScene("SelectScene", new SelectScene);
	SCENEMANAGER->addScene("DR5", new stageScene);
	shopScene* shop = new shopScene;
	SCENEMANAGER->addScene("상점씬", shop);
	SCENEMANAGER->addScene("인벤토리씬", new inventory);
	shop->invenMemoryAdressLink((inventory*)SCENEMANAGER->findScene("인벤토리씬"));

	// 배틀씬 테스트용
	vector<pokemon*>* vPokemon = new vector<pokemon*>;
	vector<pokemon*>* vPokemon2 = new vector<pokemon*>;

	skill* _temp = new bodyAttack;
	_temp->init();
	skill* _temp2 = new electricShork;
	_temp2->init();

	pokemon* isang = new pokemon;
	isang->init("거북왕", 24);
	isang->addSkill(_temp);
	isang->addSkill(_temp2);
	pokemon* dandaegi = new pokemon;
	dandaegi->init("꼬부기", 20);
	dandaegi->addSkill(_temp);
	dandaegi->addSkill(_temp2);
	vPokemon->push_back(isang);
	vPokemon2->push_back(dandaegi);

	DATABASE->setVPlayerPokemon(vPokemon);
	DATABASE->setVEnemyPokemon(vPokemon2);

	return S_OK;
}

//메모리 관련 삭제
void playGround::release(void)
{
	gameNode::release();

}

//연산
void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) SCENEMANAGER->changeScene("상점씬");

	// 배틀씬 테스트
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("battleScene");
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		SCENEMANAGER->changeScene("오프닝씬");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F4))
	{
		SCENEMANAGER->changeScene("DR5");
	}
}

//그리는거.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== 이 위는 손대지 마시오 =========================

	SCENEMANAGER->render();

	//================== 이 아래는 손대지 마시오 ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc영역에 그려준다 
}
