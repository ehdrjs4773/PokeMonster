#include "stdafx.h"
#include "stageScene.h"



stageScene::stageScene()
{
}


stageScene::~stageScene()
{
}

HRESULT stageScene::init()
{
	_stage = GYM_STEEL;

	_player = new player;
	_player->init();

	/////////////////////////////////////////////////// ���ڻ� �� �̹��� ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("drOHouse", ".\\bmps\\drHouseScene\\drOHouse.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("drOHousePixel", ".\\bmps\\drHouseScene\\drOHousePixel.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("drO", ".\\bmps\\drHouseScene\\drO.bmp", 68, 24, 4, 1, false, true, MAGENTA);
	
	/////////////////////////////////////////////////// ���� �� �̹��� ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("�����", ".\\bmps\\map\\����.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("������ȼ��浹", ".\\bmps\\map\\������ȼ��浹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("����NPC", ".\\bmps\\map\\����NPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// �븻 �� �̹��� ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("�븻��", ".\\bmps\\map\\�븻.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�븻���ȼ��浹", ".\\bmps\\map\\������ȼ��浹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�븻NPC", ".\\bmps\\map\\�븻NPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// ���� �� �̹��� ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("������", ".\\bmps\\map\\����.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�������ȼ��浹", ".\\bmps\\map\\�������ȼ��浹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("����NPC", ".\\bmps\\map\\����NPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// �巡�� �� �̹��� ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("�巡���", ".\\bmps\\map\\�巡��.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�巡����ȼ��浹", ".\\bmps\\map\\�巡����ȼ��浹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�巡��NPC", ".\\bmps\\map\\�巡��NPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// ��Ʈ �� �̹��� ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("��Ʈ��", ".\\bmps\\map\\��Ʈ.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("��Ʈ���ȼ��浹", ".\\bmps\\map\\��Ʈ���ȼ��浹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("��ƮNPC", ".\\bmps\\map\\��ƮNPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// ���� �� �̹��� ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("������", ".\\bmps\\map\\����.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�������ȼ��浹", ".\\bmps\\map\\�������ȼ��浹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("����NPC", ".\\bmps\\map\\����NPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// ���� �� �̹��� ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("������", ".\\bmps\\map\\������.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("�������ȼ��浹", ".\\bmps\\map\\�������ȼ��浹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("����NPC", ".\\bmps\\map\\����NPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// ��ö �� �̹��� ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("��ö��", ".\\bmps\\map\\��ö.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("��ö���ȼ��浹", ".\\bmps\\map\\��ö���ȼ��浹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("��öNPC", ".\\bmps\\map\\��öNPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// ��õ�� �� �̹��� ////////////////////////////////////////////////////
	//IMAGEMANAGER->addImage("��õ�ո�", ".\\bmps\\map\\����.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	//IMAGEMANAGER->addImage("������ȼ��浹", ".\\bmps\\map\\������ȼ��浹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	//IMAGEMANAGER->addImage("����NPC", ".\\bmps\\map\\����NPC.bmp", 25, 28, false, true, MAGENTA);

	////////////////////////////////////////////////////// ���ڻ� �� �ʱ�ȭ ////////////////////////////////////////////
	_drOHouse.img = IMAGEMANAGER->findImage("drOHouse");

	_drO.img = IMAGEMANAGER->findImage("drO");
	_drO.x = 240;
	_drO.y = 115;
	_drO.rc = RectMakeCenter(_drO.x, _drO.y, _drO.img->getFrameWidth(), _drO.img->getFrameHeight());
	///////////////////////////////////////////////////// ���� �� �ʱ�ȭ ///////////////////////////////////////////
	_wingMap.img = IMAGEMANAGER->findImage("�����");
	
	_wingNPC.img = IMAGEMANAGER->findImage("����NPC");
	_wingNPC.x = WINSIZEX / 2 - 12;
	_wingNPC.y = 15;
	_wingNPC.rc = RectMakeCenter(_wingNPC.x, _wingNPC.y, _wingNPC.img->getFrameWidth(), _wingNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// �븻 �� �ʱ�ȭ ///////////////////////////////////////////
	_normalMap.img = IMAGEMANAGER->findImage("�븻��");
	
	_normalNPC.img = IMAGEMANAGER->findImage("�븻NPC");
	_normalNPC.x = WINSIZEX / 2 - 12;
	_normalNPC.y = 30;
	_normalNPC.rc = RectMakeCenter(_normalNPC.x, _normalNPC.y, _normalNPC.img->getFrameWidth(), _normalNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// ���� �� �ʱ�ȭ ///////////////////////////////////////////
	_iceMap.img = IMAGEMANAGER->findImage("������");

	_iceNPC.img = IMAGEMANAGER->findImage("����NPC");
	_iceNPC.x = WINSIZEX / 2 - 12;
	_iceNPC.y = 15;
	_iceNPC.rc = RectMakeCenter(_iceNPC.x, _iceNPC.y, _iceNPC.img->getFrameWidth(), _iceNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// �巡�� �� �ʱ�ȭ ///////////////////////////////////////////
	_dragonMap.img = IMAGEMANAGER->findImage("�巡���");

	_dragonNPC.img = IMAGEMANAGER->findImage("�巡��NPC");
	_dragonNPC.x = WINSIZEX / 2;
	_dragonNPC.y = 15;
	_dragonNPC.rc = RectMakeCenter(_dragonNPC.x, _dragonNPC.y, _dragonNPC.img->getFrameWidth(), _dragonNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// ��Ʈ �� �ʱ�ȭ ///////////////////////////////////////////
	_ghostMap.img = IMAGEMANAGER->findImage("��Ʈ��");

	_ghostNPC.img = IMAGEMANAGER->findImage("��ƮNPC");
	_ghostNPC.x = WINSIZEX / 2 - 17;
	_ghostNPC.y = 60;
	_ghostNPC.rc = RectMakeCenter(_ghostNPC.x, _ghostNPC.y, _ghostNPC.img->getFrameWidth(), _ghostNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// ���� �� �ʱ�ȭ ///////////////////////////////////////////
	_bugMap.img = IMAGEMANAGER->findImage("������");

	_bugNPC.img = IMAGEMANAGER->findImage("����NPC");
	_bugNPC.x = WINSIZEX / 2;
	_bugNPC.y = 15;
	_bugNPC.rc = RectMakeCenter(_bugNPC.x, _bugNPC.y, _bugNPC.img->getFrameWidth(), _bugNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// ���� �� �ʱ�ȭ ///////////////////////////////////////////
	_fightMap.img = IMAGEMANAGER->findImage("������");

	_fightNPC.img = IMAGEMANAGER->findImage("����NPC");
	_fightNPC.x = WINSIZEX / 2 - 17;
	_fightNPC.y = 15;
	_fightNPC.rc = RectMakeCenter(_fightNPC.x, _fightNPC.y, _fightNPC.img->getFrameWidth(), _fightNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// ��ö �� �ʱ�ȭ ///////////////////////////////////////////
	_steelMap.img = IMAGEMANAGER->findImage("��ö��");

	_steelNPC.img = IMAGEMANAGER->findImage("��öNPC");
	_steelNPC.x = WINSIZEX / 2 - 12;
	_steelNPC.y = 15;
	_steelNPC.rc = RectMakeCenter(_steelNPC.x, _steelNPC.y, _steelNPC.img->getFrameWidth(), _steelNPC.img->getFrameHeight());


	
	



	return S_OK;
}

void stageScene::release()
{

}

void stageScene::update()
{
	

	_player->update();
}

void stageScene::render()
{

	switch (_stage)
	{
	case DR_O_HOUSE:
		_drOHouse.img->render(getMemDC());
		_drO.img->frameRender(getMemDC(), _drO.x, _drO.y);
		//IMAGEMANAGER->findImage("drOHousePixel")->render(getMemDC());
		break;
	case GYM_WING:
		_wingMap.img->render(getMemDC());
		_wingNPC.img->render(getMemDC(), _wingNPC.x, _wingNPC.y);
		//IMAGEMANAGER->findImage("������ȼ��浹")->render(getMemDC());
		break;
	case GYM_NORMAL:
		_normalMap.img->render(getMemDC());
		_normalNPC.img->render(getMemDC(), _normalNPC.x, _normalNPC.y);

		break;
	case GYM_ICE:
		_iceMap.img->render(getMemDC());
		_iceNPC.img->render(getMemDC(), _iceNPC.x, _iceNPC.y);
		break;
	case GYM_DRAGON:
		_dragonMap.img->render(getMemDC());
		_dragonNPC.img->render(getMemDC(), _dragonNPC.x, _dragonNPC.y);
		break;
	case GYM_GHOST:
		_ghostMap.img->render(getMemDC());
		_ghostNPC.img->render(getMemDC(), _ghostNPC.x, _ghostNPC.y);
		break;
	case GYM_BUG:
		_bugMap.img->render(getMemDC());
		_bugNPC.img->render(getMemDC(), _bugNPC.x, _bugNPC.y);
		break;
	case GYM_FIGHT:
		_fightMap.img->render(getMemDC());
		_fightNPC.img->render(getMemDC(), _fightNPC.x, _fightNPC.y);
		break;
	case GYM_STEEL:
		_steelMap.img->render(getMemDC());
		_steelNPC.img->render(getMemDC(), _steelNPC.x, _steelNPC.y);
		break;
	case CHAMPION_ROAD:
		break;
	default:
		break;
	}
	_player->render();
}