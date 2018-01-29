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

	SCENEMANAGER->addScene("����ʾ�", new worldMapScene);
	SCENEMANAGER->addScene("battleScene", new battleScene);

	SCENEMANAGER->addScene("�����׾�", new Opening);
	SCENEMANAGER->addScene("SelectScene", new SelectScene);
	shopScene* shop = new shopScene;
	SCENEMANAGER->addScene("������", shop);
	SCENEMANAGER->addScene("�κ��丮��", new inventory);
	SCENEMANAGER->addScene("PokeInfo", new MonsterBack);
	SCENEMANAGER->addScene("UI", new UI);
	SCENEMANAGER->init("�κ��丮��");

	//--------�������� �׽�Ʈ----------
	SCENEMANAGER->addScene("��������0", new drOHouse);
	SCENEMANAGER->addScene("��������1", new steelMap);
	SCENEMANAGER->addScene("��������2", new fighterMap);
	SCENEMANAGER->addScene("��������3", new ghostMap);
	SCENEMANAGER->addScene("��������4", new normalMap);
	SCENEMANAGER->addScene("��������5", new dragonMap);
	SCENEMANAGER->addScene("��������6", new bugMap);
	SCENEMANAGER->addScene("��������7", new flyMap);
	SCENEMANAGER->addScene("��������8", new iceMap);
	SCENEMANAGER->addScene("��������9", new guardian1);
	SCENEMANAGER->addScene("��������10", new guardian2);
	SCENEMANAGER->addScene("��������11", new guardian3);
	SCENEMANAGER->addScene("��������12", new guardian4);
	SCENEMANAGER->addScene("��������13", new champion);

	shop->invenMemoryAdressLink((inventory*)SCENEMANAGER->findScene("�κ��丮��"));

	// ��Ʋ�� �׽�Ʈ��
	vector<pokemon*>* vPokemon = new vector<pokemon*>;
	vector<pokemon*>* vPokemon2 = new vector<pokemon*>;

	// ## ��ų TEST ##
	//�븻
	skill* _temp = new skill;
	_temp->init("������Ÿ");
	//��
	skill* _temp2 = new skill;
	_temp2->init("Į�ٶ�");
	//��
	skill* _temp6 = new skill;
	_temp6->init("�Ҳɼ���");
	//����
	skill* _temp7 = new skill;
	_temp7->init("��������");
	//��
	skill* _temp8 = new skill;
	_temp8->init("���ؾ�");
	//����
	skill* _temp9 = new skill;
	_temp9->init("�ĵ�ź");
	//����
	skill* _temp10 = new skill;
	_temp10->init("�õ���");
	//����
	skill* _temp11 = new skill;
	_temp11->init("����");
	//Ǯ
	skill* _temp12 = new skill;
	_temp12->init("�ϵ��÷�Ʈ");

	//��Ʈ
	skill* _temp13 = new skill;
	_temp13->init("�������");
	//�巡��
	skill* _temp14 = new skill;
	_temp14->init("�巡��ũ��");
	//��ö
	skill* _temp15 = new skill;
	_temp15->init("������ĳ��");
	//������
	skill* _temp16 = new skill;
	_temp16->init("�������ֱ�");
	//����
	skill* _temp17 = new skill;
	_temp17->init("�ñ׳κ�");
	//��
	skill* _temp18 = new skill;
	_temp18->init("�����ĵ�");
	//����
	skill* _temp19 = new skill;
	_temp19->init("�������");
	//����
	skill* _temp20 = new skill;
	_temp20->init("����");



	// =======
	skill* _temp3 = new skill;
	_temp3->init("�����ġ��");
	skill* _temp4 = new skill;
	_temp4->init("�����ġ��");
	skill* _temp5 = new skill;
	_temp5->init("�����ġ��");
	// =========

	pokemon* isang = new pokemon;
	isang->init("�̻��ؾ�", 500);
	isang->addSkill(_temp15);
	isang->addSkill(_temp17);
	pokemon* tuttleKing = new pokemon;
	tuttleKing->init("�źϿ�", 36);
	tuttleKing->addSkill(_temp11);
	pokemon* dandaegi = new pokemon;
	dandaegi->init("�ܵ���", 99);
	dandaegi->addSkill(_temp12);

	pokemon* ggorat = new pokemon;
	ggorat->init("����", INT_MAX);
	ggorat->addSkill(_temp5);
	vPokemon->push_back(isang);
	vPokemon->push_back(tuttleKing);
	vPokemon2->push_back(dandaegi);
	vPokemon2->push_back(ggorat);

	DATABASE->setVPlayerPokemon(vPokemon);
	DATABASE->setVEnemyPokemon(vPokemon2);

	SCENEMANAGER->init("PokeInfo");
	SCENEMANAGER->init("UI");

	//SCENEMANAGER->changeScene("�����׾�");

	return S_OK;
}

//�޸� ���� ����
void playGround::release(void)
{
	gameNode::release();

}

//����
void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene("����ʾ�");
		SCENEMANAGER->init("����ʾ�");
	}

	// ��Ʋ�� �׽�Ʈ
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene("battleScene");
		SCENEMANAGER->init("battleScene");
		SCENEMANAGER->findScene("battleScene")->setDestScene("����ʾ�");
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		SCENEMANAGER->changeScene("�����׾�");
		SCENEMANAGER->init("�����׾�");
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
	//--------�������� �׽�Ʈ----------
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD0))	//���ڻ�
	{
		SCENEMANAGER->changeScene("��������13");
		SCENEMANAGER->init("��������13");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD1))	//����
	{
		SCENEMANAGER->changeScene("��������7");
		SCENEMANAGER->init("��������7");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD2))	//����
	{
		SCENEMANAGER->changeScene("��������2");
		SCENEMANAGER->init("��������2");
	}
	
}

//�׸��°�.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== �� ���� �մ��� ���ÿ� =========================

	SetBkMode(getMemDC(), TRANSPARENT);
	SCENEMANAGER->render();

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}
