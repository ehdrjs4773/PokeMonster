#pragma once
#include "gameNode.h"
#include <vector>

class player;

class stageManager : public gameNode
{
protected:
	player* _player;
	image* _gymLeader;		//Ã¼À°°ü °üÀå

	bool _isWin;
	vector<pokemon*> _vPokemon;

	int _regenTime;
	int _currentStage;

public:
	stageManager();
	~stageManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void regenPokemon();

	inline bool getIsWin() { return _isWin; }
	inline void setIsWin(bool win) { _isWin = win; }
	inline void setPlayerAddressLink(player* player) { _player = player; }
};

