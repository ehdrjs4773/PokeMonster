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

	//사운드 
	SOUNDMANAGER->addSound("배틀씬 테마곡", "battleBgm.mp3", true, true);
	SOUNDMANAGER->addSound("레드의 테마곡", ".//bossBgm.mp3", true, true);
	SOUNDMANAGER->addSound("오박사 테마곡", "drOBgm.mp3", true, true);
	SOUNDMANAGER->addSound("월드맵 테마곡", "worldBgm.mp3", true, true);


	_player = new player;
	_player->init();
	DATABASE->setPlayerMemory(_player);

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
	SCENEMANAGER->addScene("ending", new Ending);
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

	SCENEMANAGER->init("PokeInfo");
	SCENEMANAGER->init("UI");
	SCENEMANAGER->init("오프닝씬");
	SCENEMANAGER->init("ending");
	
	SCENEMANAGER->changeScene("오프닝씬");

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
