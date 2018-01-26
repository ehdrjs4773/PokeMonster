#include "stdafx.h"
#include "dialogue.h"



dialogue::dialogue()
{
}


dialogue::~dialogue()
{
}

HRESULT dialogue::init(float dt, int printLines, LANGUAGE lan)
{
	_dialogueTime = dt;
	_elapsedTime = 0;
	_printLinesNum = printLines;
	_language = lan;

	_length = new int[_printLinesNum];

	return S_OK;
}

void dialogue::release()
{
	SAFE_DELETE_ARRAY(_length);
}

void dialogue::update()
{
	_elapsedTime++;
	if (_elapsedTime % _dialogueTime == 0)
	{
		for (int i = 0; i < _printLinesNum; ++i)
		{
			if (i >= _vString.size()) break;
			if (_currentLine + i >= _vString.size()) break;
			if (_length[i] >= strlen(_vString[_currentLine + i])) continue;

			_length[i] += _language;
			if (_length[i] > strlen(_vString[_currentLine + i]))
				_length[i] = strlen(_vString[_currentLine + i]);

			break;
		}
	}
}

void dialogue::render(HDC hdc)
{
	for (int i = 0; i < _printLinesNum; ++i)
	{
		if (i >= _vString.size()) break;
		if (_currentLine + i >= _vString.size()) break;

		TextOut(hdc, _startX, _startY + 20 * i, _vString[_currentLine + i], _length[i]);
	}
}

void dialogue::loadingTextFile(const char* fileName)
{
	// 일단 벡터 비우고
	_vString.clear();

	// 맨 처음 대사부터 뜨게 하고
	_currentLine = 0;

	for (int i = 0; i < _printLinesNum; ++i)
		_length[i] = 0;

	// Text파일을 읽어와서
	vector<string> temp = TXTDATA->txtLoad(fileName);

	// 벡터에 차곡차곡 담아쥼

	for (int i = 0; i < temp.size(); ++i)
	{
		char* tempStr = new char[strlen(temp[i].c_str()) + 1];
		strcpy(tempStr, temp[i].c_str());
		_vString.push_back(tempStr);
	}
}