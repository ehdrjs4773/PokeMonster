#pragma once
#include "gameNode.h"
#include <vector>

class player;

class stageManager : public gameNode
{
protected:
	player* _player;
	image* _gymLeader;		//체육관 관장

	bool _isWin;
	vector<pokemon*> _vPokemon;

public:
	stageManager();
	~stageManager();

	HRESULT init();
	void release();
	void update();
	void render();

	inline bool getIsWin() { return _isWin; }
	inline void setPlayerAddressLink(player* player) { _player = player; }
};

