#include "stdafx.h"
#include "playGround.h"

void playGround::imageInit()
{
	// ================================================
	//				## 이펙트들 등록 ##
	// ================================================
	EFFECTMANAGER->addEffect("노말_player", ".\\bmps\\effects\\beamPlayer.bmp", 1280, 224, 320, 224, 1.0f, 0.3f, 1);
	EFFECTMANAGER->addEffect("노말_enemy", ".\\bmps\\effects\\beamEnemy.bmp", 1280, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("불_player", ".\\bmps\\effects\\firePlayer.bmp", 1280, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("불_enemy", ".\\bmps\\effects\\fireEnemy.bmp", 1280, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("물_player", ".\\bmps\\effects\\waterPlayer.bmp", 1280, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("물_enemy", ".\\bmps\\effects\\waterEnemy.bmp", 1280, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("전기_player", ".\\bmps\\effects\\lightningPlayer.bmp", 1600, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("전기_enemy", ".\\bmps\\effects\\lightningEnemy.bmp", 1600, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("풀_player", ".\\bmps\\effects\\leafPlayer.bmp", 2240, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("풀_enemy", ".\\bmps\\effects\\leafEnemy.bmp", 2240, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("얼음_player", ".\\bmps\\effects\\icePlayer.bmp", 2240, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("얼음_enemy", ".\\bmps\\effects\\iceEnemy.bmp", 2240, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("격투_player", ".\\bmps\\effects\\handPlayer.bmp", 960, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("격투_enemy", ".\\bmps\\effects\\handEnemy.bmp", 960, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("독_player", ".\\bmps\\effects\\poisonPlayer.bmp", 2560, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("독_enemy", ".\\bmps\\effects\\poisonEnemy.bmp", 2560, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("바위_player", ".\\bmps\\effects\\rockPlayer.bmp", 1920, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("바위_enemy", ".\\bmps\\effects\\rockEnemy.bmp", 1920, 224, 320, 224, 1.0f, 1.0f, 1);
}
