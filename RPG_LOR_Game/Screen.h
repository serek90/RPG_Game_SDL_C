#pragma once
#include "Game.h"


class Screen
{
protected:
	bool _isOn;

public:

	Screen() { _isOn = true; };
	virtual ~Screen() { };
	virtual int update() = 0;
	virtual void render() = 0;
	virtual void handleEvent(SDL_Event event) = 0;
	virtual Screen* procedNext() = 0;

	//visible
	bool isOn() {return _isOn; }
	void off() { _isOn = false;  }
};

