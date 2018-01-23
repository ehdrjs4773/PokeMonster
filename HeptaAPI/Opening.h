#pragma once
#include "gameNode.h"

enum OpeningSin
{
	Opening_One,
	Opening_Two,
	Opening_Three,
	Opening_Four
};

class Opening : public gameNode
{
private :
	
	OpeningSin _opening;



public:
	Opening();
	~Opening();


	virtual HRESULT init(void);
	virtual void render(void);
	virtual void update(void);
	virtual void release(void);

};

