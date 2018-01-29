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

	this->imageInit();

	SCENEMANAGER->addScene("월드맵씬", new worldMapScene);
	SCENEMANAGER->addScene("battleScene", new battleScene);

	SCENEMANAGER->addScene("오프닝씬", new Opening);
	SCENEMANAGER->addScene("SelectScene", new SelectScene);
	shopScene* shop = new shopScene;
	SCENEMANAGER->addScene("상점씬", shop);
	SCENEMANAGER->addScene("인벤토리씬", new inventory);
	SCENEMANAGER->addScene("PokeInfo", new MonsterBack);
	SCENEMANAGER->addScene("UI", new UI);
	SCENEMANAGER->init("인벤토리씬");

	//--------수테이지 테스트----------
	SCENEMANAGER->addScene("스테이지0", new drOHouse);
	SCENEMANAGER->addScene("스테이지1", new steelMap);
	SCENEMANAGER->addScene("스테이지2", new fighterMap);
	SCENEMANAGER->addScene("스테이지3", new ghostMap);
	SCENEMANAGER->addScene("스테이지4", new normalMap);
	SCENEMANAGER->addScene("스테이지5", new dragonMap);
	SCENEMANAGER->addScene("스테이지6", new bugMap);
	SCENEMANAGER->addScene("스테이지7", new flyMap);
	SCENEMANAGER->addScene("스테이지8", new iceMap);
	SCENEMANAGER->addScene("스테이지9", new guardian1);
	SCENEMANAGER->addScene("스테이지10", new guardian2);
	SCENEMANAGER->addScene("스테이지11", new guardian3);
	SCENEMANAGER->addScene("스테이지12", new guardian4);
	SCENEMANAGER->addScene("스테이지13", new champion);


	shop->invenMemoryAdressLink((inventory*)SCENEMANAGER->findScene("인벤토리씬"));

	// 배틀씬 테스트용
	vector<pokemon*>* vPokemon = new vector<pokemon*>;
	vector<pokemon*>* vPokemon2 = new vector<pokemon*>;

	skill* _temp = new skill;
	_temp->init("몸통박치기");
	skill* _temp2 = new skill;
	_temp2->init("물대포");
	skill* _temp3 = new skill;
	_temp3->init("몸통박치기");
	skill* _temp4 = new skill;
	_temp4->init("몸통박치기");
	skill* _temp5 = new skill;
	_temp5->init("몸통박치기");

	pokemon* isang = new pokemon;
	isang->init("이상해씨", 24);
	isang->addSkill(_temp);
	isang->addSkill(_temp2);
	pokemon* tuttleKing = new pokemon;
	tuttleKing->init("거북왕", 36);
	tuttleKing->addSkill(_temp4);
	pokemon* dandaegi = new pokemon;
	dandaegi->init("단데기", 20);
	dandaegi->addSkill(_temp3);
	pokemon* ggorat = new pokemon;
	ggorat->init("꼬렛", 30);
	ggorat->addSkill(_temp5);
	vPokemon->push_back(isang);
	vPokemon->push_back(tuttleKing);
	vPokemon2->push_back(dandaegi);
	vPokemon2->push_back(ggorat);

	DATABASE->setVPlayerPokemon(vPokemon);
	DATABASE->setVEnemyPokemon(vPokemon2);

	SCENEMANAGER->init("PokeInfo");
	SCENEMANAGER->init("UI");

	//SCENEMANAGER->changeScene("오프닝씬");

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
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene("월드맵씬");
		SCENEMANAGER->init("월드맵씬");
	}

	// 배틀씬 테스트
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("battleScene");
		SCENEMANAGER->init("battleScene");
		SCENEMANAGER->findScene("battleScene")->setDestScene("월드맵씬");
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		SCENEMANAGER->changeScene("오프닝씬");
		SCENEMANAGER->init("오프닝씬");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F4))
	{
		SCENEMANAGER->changeScene("DR5");
		SCENEMANAGER->init("DR5");
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F12))
	{
		SCENEMANAGER->changeScene(SCENEMANAGER->getLastSceneName());
	}

	//if (KEYMANAGER->isOnceKeyDown(VK_F5))
	//{
	//	SCENEMANAGER->changeScene("UI");
	//}
	//--------수테이지 테스트----------
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD0))	//오박사
	{
		SCENEMANAGER->changeScene("스테이지13");
		SCENEMANAGER->init("스테이지13");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD1))	//비행
	{
		SCENEMANAGER->changeScene("스테이지7");
		SCENEMANAGER->init("스테이지7");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD2))	//격투
	{
		SCENEMANAGER->changeScene("스테이지2");
		SCENEMANAGER->init("스테이지2");
	}
	
}

//그리는거.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== 이 위는 손대지 마시오 =========================

	SetBkMode(getMemDC(), TRANSPARENT);
	SCENEMANAGER->render();

	//================== 이 아래는 손대지 마시오 ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc영역에 그려준다 
}
