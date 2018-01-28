#include "stdafx.h"
#include "playGround.h"

void playGround::imageInit()
{
	// ================================================
	//				## ����Ʈ�� ��� ##
	// ================================================
	EFFECTMANAGER->addEffect("�븻_player", ".\\bmps\\effects\\beamPlayer.bmp", 1280, 224, 320, 224, 1.0f, 0.3f, 1);
	EFFECTMANAGER->addEffect("�븻_enemy", ".\\bmps\\effects\\beamEnemy.bmp", 1280, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("��_player", ".\\bmps\\effects\\firePlayer.bmp", 1280, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("��_enemy", ".\\bmps\\effects\\fireEnemy.bmp", 1280, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("��_player", ".\\bmps\\effects\\waterPlayer.bmp", 1280, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("��_enemy", ".\\bmps\\effects\\waterEnemy.bmp", 1280, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("����_player", ".\\bmps\\effects\\lightningPlayer.bmp", 1600, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("����_enemy", ".\\bmps\\effects\\lightningEnemy.bmp", 1600, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("Ǯ_player", ".\\bmps\\effects\\leafPlayer.bmp", 2240, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("Ǯ_enemy", ".\\bmps\\effects\\leafEnemy.bmp", 2240, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("����_player", ".\\bmps\\effects\\icePlayer.bmp", 2240, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("����_enemy", ".\\bmps\\effects\\iceEnemy.bmp", 2240, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("����_player", ".\\bmps\\effects\\handPlayer.bmp", 960, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("����_enemy", ".\\bmps\\effects\\handEnemy.bmp", 960, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("��_player", ".\\bmps\\effects\\poisonPlayer.bmp", 2560, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("��_enemy", ".\\bmps\\effects\\poisonEnemy.bmp", 2560, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("����_player", ".\\bmps\\effects\\rockPlayer.bmp", 1920, 224, 320, 224, 1.0f, 1.0f, 1);
	EFFECTMANAGER->addEffect("����_enemy", ".\\bmps\\effects\\rockEnemy.bmp", 1920, 224, 320, 224, 1.0f, 1.0f, 1);
}
