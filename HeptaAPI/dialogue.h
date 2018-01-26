#pragma once
#include "singletonBase.h"
#include <vector>

enum LANGUAGE
{
	LANGUAGE_DEFAULT = 1,
	LANGUAGE_KOREAN,
	LANGUAGE_END
};

class dialogue : public singletonBase<dialogue>
{
private:
	vector<string>			 _vString;
	vector<string>::iterator _vStringIter;

	int _dialogueTime;
	int _elapsedTime;

	float _startX, _startY;
	int* _length;

	int _currentLine;
	int _printLinesNum;
	LANGUAGE _language;

public:
	dialogue();
	~dialogue();

	HRESULT init(float dt, int printLines, LANGUAGE lan);
	void release();
	void update();
	void render(HDC hdc);

	void loadingTextFile(const char* fileName);

	//							sour¸¦				dest·Î ¹Ù²ãÁÜ
	void replaceAll(const string sour, const string dest);

	inline int getCurrentLine() { return _currentLine; }
	inline void setCurrentLine(int line)
	{
		_currentLine = line;
		if (_currentLine > _vString.size() - (_printLinesNum - 1))
			_currentLine = _vString.size() - (_printLinesNum - 1);

		for (int i = 0; i < _printLinesNum; ++i)
			_length[i] = 0;
	}

	inline POINT getPoint() { return PointMake(_startX, _startY); }
	inline void setPoint(POINT pos)
	{
		_startX = pos.x;
		_startY = pos.y;
	}
};

