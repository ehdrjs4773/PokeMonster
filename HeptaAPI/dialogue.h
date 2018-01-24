#pragma once
#include "singletonBase.h"
#include <vector>

class dialogue : public singletonBase<dialogue>
{
private:
	vector<char*>			_vString;
	vector<char*>::iterator _vStringIter;

	int _dialogueTime;
	int _elapsedTime;

	float _startX, _startY;
	int _length;
	char _str[1024];

public:
	dialogue();
	~dialogue();

	HRESULT init(float dt);
	void update();
	void render(HDC hdc);

	void loadingTextFile(string fileName);

	inline void setString(const char* str)
	{
		sprintf(_str, "%s", str);
		_length = 0;
		_elapsedTime = 0;
	}
	inline void setPoint(POINT pos)
	{
		_startX = pos.x;
		_startY = pos.y;
	}
};

