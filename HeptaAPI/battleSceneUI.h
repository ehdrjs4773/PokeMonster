#pragma once
#include "gameNode.h"

// ���漱��
class battleScene;
enum ELEMENT;

class battleSceneUI : public gameNode
{
private:
	battleScene* _battleScene;

	RECT _selectSequenceRect[2][2];
	RECT _skillPrintRect[4];
	POINT _selectArrowPoint;
	int _skillSelectNum;

	// BATTLE_SELECT �������� ���� ������
	bool _isFightSelect;
	bool _isBagSelect;
	bool _isPokemonSelect;
	bool _isRunAwaySelect;

public:
	battleSceneUI();
	~battleSceneUI();

	HRESULT init();
	void release();
	void update();
	void render();

	void printElement(ELEMENT el);

	inline void setMemoryAddressLink(battleScene* battle) { _battleScene = battle; }
};

