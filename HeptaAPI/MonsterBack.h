#pragma once
#include "gameNode.h"
#include "progressBar.h"

class battleSceneUI;

struct PokeInfo
{
	RECT rc;
	RECT PokeImageRc;
	POINT NameTxt;
	POINT HpTxt;
	image* RectImage;
	image* PoketImage;
	int Level;
	bool Catch; 
	string strKey;
	int count;
	int currentFrameX;
	progressBar* _playerHpBar;
	
};



class MonsterBack : public gameNode
{
private :
	RECT _CancleRc;

	battleSceneUI* _battleSceneUI;

	

	PokeInfo _PokeInfo[6];




public:
	MonsterBack();
	~MonsterBack();

	virtual HRESULT init(void);
	virtual void render(void);
	virtual void update(void);
	virtual void release(void);

	inline void battleSceneUIMemoruAddressLink(battleSceneUI* ui) { _battleSceneUI = ui; }

};

