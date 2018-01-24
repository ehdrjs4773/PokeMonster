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

	DIALOGUE->loadingTextFile(".\\textData\\battleScene_dialogue.txt");
	DIALOGUE->setPoint(PointMake(WINSIZEX / 2, WINSIZEY / 2));

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
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) SCENEMANAGER->changeScene("월드맵씬");

	// 배틀씬 테스트
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		vector<pokemon*> vPokemon;
		vector<pokemon*> vPokemon2;

		pokemon* pika = new pokemon;
		vPokemon.push_back(pika);
		vPokemon2.push_back(pika);

		DATABASE->setVPlayerPokemon(&vPokemon);
		DATABASE->setVEnemyPokemon(&vPokemon2);

		SCENEMANAGER->changeScene("battleScene");
	}

	DIALOGUE->update();
}

//그리는거.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== 이 위는 손대지 마시오 =========================

	SCENEMANAGER->render();
	DIALOGUE->render(getMemDC());

	//================== 이 아래는 손대지 마시오 ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc영역에 그려준다 
}
