#pragma once
#include "gameNode.h"


enum SelcetScene_Type
{
	SelectScene_one,
	SelectScene_Two,
	SelectScene_Three,
	SelectScene_Four
};



class SelectScene : public gameNode
{

private:
	
	int _alpha;
	int _alphaBall;
	int _npcAlpha;
	
	SelcetScene_Type _SelectScene;

	int _currentFrameX;
	int _count;

	float _dr5x, _dr5y;



public:
	SelectScene();
	~SelectScene();

	virtual HRESULT init(void);
	virtual void render(void);
	virtual void update(void);
	virtual void release(void);


};

