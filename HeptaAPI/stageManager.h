#pragma once
#include "gameNode.h"

class player;


class stageManager : public gameNode
{
protected:
	player* _player;
	image* _gymLeader;		//Ã¼À°°ü °üÀå

	bool _isWin;

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

