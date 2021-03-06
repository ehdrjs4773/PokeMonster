#pragma once
#include "gameNode.h"
#include "progressBar.h"

class battleSceneUI;
class inventory;

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


struct PokeChange
{
	RECT rc;
	RECT rc1;
};



class MonsterBack : public gameNode
{
private :
	RECT _CancleRc;
	
	PokeChange _PokeChage;


	int _SelectPokeMonNum;


	inventory* _inventory;
	battleSceneUI* _battleSceneUI;

	bool _isChange;
	bool _isLife;
	

	PokeInfo _PokeInfo[6];




public:
	MonsterBack();
	~MonsterBack();

	virtual HRESULT init(void);
	virtual void render(void);
	virtual void update(void);
	virtual void release(void);

	inline void battleSceneUIMemoruAddressLink(battleSceneUI* ui) { _battleSceneUI = ui; }
	inline void inventoryMemoryAddressLink(inventory* ui) { _inventory = ui; }
};

