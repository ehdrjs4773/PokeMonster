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

	/////////////////////////////////////////////////// ¿À¹Ú»ç ¾À ÀÌ¹ÌÁö ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("drOHouse", ".\\bmps\\drHouseScene\\drOHouse.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("drOHousePixel", ".\\bmps\\drHouseScene\\drOHousePixel.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("drO", ".\\bmps\\drHouseScene\\drO.bmp", 68, 24, 4, 1, false, true, MAGENTA);
	
	/////////////////////////////////////////////////// ºñÇà ¾À ÀÌ¹ÌÁö ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("ºñÇà¸Ê", ".\\bmps\\map\\ºñÇà.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("ºñÇà¸ÊÇÈ¼¿Ãæµ¹", ".\\bmps\\map\\ºñÇà¸ÊÇÈ¼¿Ãæµ¹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("ºñÇàNPC", ".\\bmps\\map\\ºñÇàNPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// ³ë¸» ¾À ÀÌ¹ÌÁö ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("³ë¸»¸Ê", ".\\bmps\\map\\³ë¸».bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("³ë¸»¸ÊÇÈ¼¿Ãæµ¹", ".\\bmps\\map\\ºñÇà¸ÊÇÈ¼¿Ãæµ¹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("³ë¸»NPC", ".\\bmps\\map\\³ë¸»NPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// ¾óÀ½ ¾À ÀÌ¹ÌÁö ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("¾óÀ½¸Ê", ".\\bmps\\map\\¾óÀ½.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("¾óÀ½¸ÊÇÈ¼¿Ãæµ¹", ".\\bmps\\map\\¾óÀ½¸ÊÇÈ¼¿Ãæµ¹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("¾óÀ½NPC", ".\\bmps\\map\\¾óÀ½NPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// µå·¡°ï ¾À ÀÌ¹ÌÁö ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("µå·¡°ï¸Ê", ".\\bmps\\map\\µå·¡°ï.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("µå·¡°ï¸ÊÇÈ¼¿Ãæµ¹", ".\\bmps\\map\\µå·¡°ï¸ÊÇÈ¼¿Ãæµ¹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("µå·¡°ïNPC", ".\\bmps\\map\\µå·¡°ïNPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// °í½ºÆ® ¾À ÀÌ¹ÌÁö ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("°í½ºÆ®¸Ê", ".\\bmps\\map\\°í½ºÆ®.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("°í½ºÆ®¸ÊÇÈ¼¿Ãæµ¹", ".\\bmps\\map\\°í½ºÆ®¸ÊÇÈ¼¿Ãæµ¹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("°í½ºÆ®NPC", ".\\bmps\\map\\°í½ºÆ®NPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// ¹ú·¹ ¾À ÀÌ¹ÌÁö ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("¹ú·¹¸Ê", ".\\bmps\\map\\¹ú·¹.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("¹ú·¹¸ÊÇÈ¼¿Ãæµ¹", ".\\bmps\\map\\¹ú·¹¸ÊÇÈ¼¿Ãæµ¹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("¹ú·¹NPC", ".\\bmps\\map\\¹ú·¹NPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// °İÅõ ¾À ÀÌ¹ÌÁö ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("°İÅõ¸Ê", ".\\bmps\\map\\°İÅõ¸Ê.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("°İÅõ¸ÊÇÈ¼¿Ãæµ¹", ".\\bmps\\map\\°İÅõ¸ÊÇÈ¼¿Ãæµ¹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("°İÅõNPC", ".\\bmps\\map\\°İÅõNPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// °­Ã¶ ¾À ÀÌ¹ÌÁö ////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("°­Ã¶¸Ê", ".\\bmps\\map\\°­Ã¶.bmp", 0, 0, WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("°­Ã¶¸ÊÇÈ¼¿Ãæµ¹", ".\\bmps\\map\\°­Ã¶¸ÊÇÈ¼¿Ãæµ¹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	IMAGEMANAGER->addImage("°­Ã¶NPC", ".\\bmps\\map\\°­Ã¶NPC.bmp", 25, 28, false, true, MAGENTA);

	/////////////////////////////////////////////////// »çÃµ¿Õ ¾À ÀÌ¹ÌÁö ////////////////////////////////////////////////////
	//IMAGEMANAGER->addImage("»çÃµ¿Õ¸Ê", ".\\bmps\\map\\ºñÇà.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	//IMAGEMANAGER->addImage("ºñÇà¸ÊÇÈ¼¿Ãæµ¹", ".\\bmps\\map\\ºñÇà¸ÊÇÈ¼¿Ãæµ¹.bmp", WINSIZEX, WINSIZEY, false, true, MAGENTA);
	//IMAGEMANAGER->addImage("ºñÇàNPC", ".\\bmps\\map\\ºñÇàNPC.bmp", 25, 28, false, true, MAGENTA);

	////////////////////////////////////////////////////// ¿À¹Ú»ç ¾À ÃÊ±âÈ­ ////////////////////////////////////////////
	_drOHouse.img = IMAGEMANAGER->findImage("drOHouse");

	_drO.img = IMAGEMANAGER->findImage("drO");
	_drO.x = 240;
	_drO.y = 115;
	_drO.rc = RectMakeCenter(_drO.x, _drO.y, _drO.img->getFrameWidth(), _drO.img->getFrameHeight());
	///////////////////////////////////////////////////// ºñÇà ¾À ÃÊ±âÈ­ ///////////////////////////////////////////
	_wingMap.img = IMAGEMANAGER->findImage("ºñÇà¸Ê");
	
	_wingNPC.img = IMAGEMANAGER->findImage("ºñÇàNPC");
	_wingNPC.x = WINSIZEX / 2 - 12;
	_wingNPC.y = 15;
	_wingNPC.rc = RectMakeCenter(_wingNPC.x, _wingNPC.y, _wingNPC.img->getFrameWidth(), _wingNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// ³ë¸» ¾À ÃÊ±âÈ­ ///////////////////////////////////////////
	_normalMap.img = IMAGEMANAGER->findImage("³ë¸»¸Ê");
	
	_normalNPC.img = IMAGEMANAGER->findImage("³ë¸»NPC");
	_normalNPC.x = WINSIZEX / 2 - 12;
	_normalNPC.y = 30;
	_normalNPC.rc = RectMakeCenter(_normalNPC.x, _normalNPC.y, _normalNPC.img->getFrameWidth(), _normalNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// ¾óÀ½ ¾À ÃÊ±âÈ­ ///////////////////////////////////////////
	_iceMap.img = IMAGEMANAGER->findImage("¾óÀ½¸Ê");

	_iceNPC.img = IMAGEMANAGER->findImage("¾óÀ½NPC");
	_iceNPC.x = WINSIZEX / 2 - 12;
	_iceNPC.y = 15;
	_iceNPC.rc = RectMakeCenter(_iceNPC.x, _iceNPC.y, _iceNPC.img->getFrameWidth(), _iceNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// µå·¡°ï ¾À ÃÊ±âÈ­ ///////////////////////////////////////////
	_dragonMap.img = IMAGEMANAGER->findImage("µå·¡°ï¸Ê");

	_dragonNPC.img = IMAGEMANAGER->findImage("µå·¡°ïNPC");
	_dragonNPC.x = WINSIZEX / 2;
	_dragonNPC.y = 15;
	_dragonNPC.rc = RectMakeCenter(_dragonNPC.x, _dragonNPC.y, _dragonNPC.img->getFrameWidth(), _dragonNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// °í½ºÆ® ¾À ÃÊ±âÈ­ ///////////////////////////////////////////
	_ghostMap.img = IMAGEMANAGER->findImage("°í½ºÆ®¸Ê");

	_ghostNPC.img = IMAGEMANAGER->findImage("°í½ºÆ®NPC");
	_ghostNPC.x = WINSIZEX / 2 - 17;
	_ghostNPC.y = 60;
	_ghostNPC.rc = RectMakeCenter(_ghostNPC.x, _ghostNPC.y, _ghostNPC.img->getFrameWidth(), _ghostNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// ¹ú·¹ ¾À ÃÊ±âÈ­ ///////////////////////////////////////////
	_bugMap.img = IMAGEMANAGER->findImage("¹ú·¹¸Ê");

	_bugNPC.img = IMAGEMANAGER->findImage("¹ú·¹NPC");
	_bugNPC.x = WINSIZEX / 2;
	_bugNPC.y = 15;
	_bugNPC.rc = RectMakeCenter(_bugNPC.x, _bugNPC.y, _bugNPC.img->getFrameWidth(), _bugNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// °İÅõ ¾À ÃÊ±âÈ­ ///////////////////////////////////////////
	_fightMap.img = IMAGEMANAGER->findImage("°İÅõ¸Ê");

	_fightNPC.img = IMAGEMANAGER->findImage("°İÅõNPC");
	_fightNPC.x = WINSIZEX / 2 - 17;
	_fightNPC.y = 15;
	_fightNPC.rc = RectMakeCenter(_fightNPC.x, _fightNPC.y, _fightNPC.img->getFrameWidth(), _fightNPC.img->getFrameHeight());
	///////////////////////////////////////////////////// °­Ã¶ ¾À ÃÊ±âÈ­ ///////////////////////////////////////////
	_steelMap.img = IMAGEMANAGER->findImage("°­Ã¶¸Ê");

	_steelNPC.img = IMAGEMANAGER->findImage("°­Ã¶NPC");
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
		//IMAGEMANAGER->findImage("ºñÇà¸ÊÇÈ¼¿Ãæµ¹")->render(getMemDC());
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