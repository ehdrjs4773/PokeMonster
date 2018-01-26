#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{

}

// exp바 초기화
HRESULT progressBar::init(string strKey, int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	//_progressBarTop = new image;
	//_progressBarTop->init(".\\bmps\\hpBarTop.bmp", (float)x, (float)y, width, height, true, RGB(255, 0, 255));
	//
	//_progressBarBottom = new image;
	//_progressBarBottom->init(".\\bmps\\hpBarBottom.bmp", (float)x, (float)y, width, height, true, RGB(255, 0, 255));

	_strKey = strKey;
	string tempFilePath = ".\\bmps\\battleScene\\UI\\" + strKey + "frontBar.bmp";
	_progressBarTop = IMAGEMANAGER->addImage(strKey + "frontBar", tempFilePath.c_str(), x, y, width, height, false, true, RGB(255, 0, 255));
	tempFilePath = ".\\bmps\\battleScene\\UI\\" + strKey + "backBar.bmp";
	_progressBarBottom = IMAGEMANAGER->addImage(strKey + "backBar", tempFilePath.c_str(), x, y, width, height, false, true, RGB(255, 0, 255));

	//설정된 가로크기로!
	_width = 0;

	return S_OK;
}

// hp바 초기화
HRESULT progressBar::init(string strKey, int x, int y, int width, int height, int currentGauge, int maxGauge)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	//_progressBarTop = new image;
	//_progressBarTop->init(".\\bmps\\hpBarTop.bmp", (float)x, (float)y, width, height, true, RGB(255, 0, 255));
	//
	//_progressBarBottom = new image;
	//_progressBarBottom->init(".\\bmps\\hpBarBottom.bmp", (float)x, (float)y, width, height, true, RGB(255, 0, 255));

	_strKey = strKey;
	string tempFilePath = ".\\bmps\\battleScene\\UI\\" + strKey + "frontBar";
	IMAGEMANAGER->addImage(strKey + "frontBar_high", (tempFilePath + "_high.bmp").c_str(), x, y, width, height, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(strKey + "frontBar_middle", (tempFilePath + "_middle.bmp").c_str(), x, y, width, height, false, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(strKey + "frontBar_low", (tempFilePath + "_low.bmp").c_str(), x, y, width, height, false, true, RGB(255, 0, 255));

	int percent = (currentGauge / maxGauge) * 100;
	if (percent > 50)
		_progressBarTop = IMAGEMANAGER->findImage(strKey + "frontBar_high");
	else if (percent > 30)
		_progressBarTop = IMAGEMANAGER->findImage(strKey + "frontBar_middle");
	else
		_progressBarTop = IMAGEMANAGER->findImage(strKey + "frontBar_low");

	tempFilePath = ".\\bmps\\battleScene\\UI\\" + strKey + "backBar.bmp";
	_progressBarBottom = IMAGEMANAGER->addImage(strKey + "backBar", tempFilePath.c_str(), x, y, width, height, false, true, RGB(255, 0, 255));

	//설정된 가로크기로!
	_width = _progressBarTop->getWidth();

	return S_OK;
}

void progressBar::release()
{
}

void progressBar::update()
{
	_rcProgress = RectMake(_x, _y, _progressBarTop->getWidth(), _progressBarTop->getHeight());
}

void progressBar::render()									  
{
	//IMAGEMANAGER->render(_strKey + "backBar", getMemDC(),
	//	_rcProgress.left,
	//	_y, 0, 0,
	//	_progressBarBottom->getWidth(), _progressBarBottom->getHeight());
	//
	//IMAGEMANAGER->render(_strKey + "frontBar", getMemDC(),
	//	_rcProgress.left,
	//	_y, 0, 0,
	//	_width, _progressBarBottom->getHeight());

	_progressBarBottom->render(getMemDC(),
		_rcProgress.left,
		_y, 0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());
	
	_progressBarTop->render(getMemDC(),
		_rcProgress.left,
		_y, 0, 0,
		_width, _progressBarBottom->getHeight());

}

void progressBar::setGauge(float currentGauge, float maxGauge, bool isHP)
{
	float width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
	// hp가 천천히 줄어들게
	if (isHP)
	{
		if (_width > width)
		{
			_width -= 0.5;
			if (_width < width)
				_width = width;
		}

		int percent = (currentGauge / maxGauge) * 100;
		if (percent > 50)
			_progressBarTop = IMAGEMANAGER->findImage(_strKey + "frontBar_high");
		else if (percent > 30)
			_progressBarTop = IMAGEMANAGER->findImage(_strKey + "frontBar_middle");
		else
			_progressBarTop = IMAGEMANAGER->findImage(_strKey + "frontBar_low");
	}
	// exp가 천천히 오르게
	else
	{
		if (_width < width)
		{
			_width++;
			if (_width > width)
				_width = width;
		}
	}
}
