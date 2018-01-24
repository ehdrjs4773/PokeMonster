#include "stdafx.h"
#include "dialogue.h"



dialogue::dialogue()
{
}


dialogue::~dialogue()
{
}

HRESULT dialogue::init(float dt)
{
	_dialogueTime = dt;
	_elapsedTime = 0;

	return S_OK;
}

void dialogue::update()
{
	_elapsedTime++;
	if (_elapsedTime % _dialogueTime == 0)
	{
		_length += 2;
		if (_length > strlen(_str))
			_length = strlen(_str);
	}
}

void dialogue::render(HDC hdc)
{
	TextOut(hdc, _startX, _startY, _str, _length);
}

void dialogue::loadingTextFile(string fileName)
{

}