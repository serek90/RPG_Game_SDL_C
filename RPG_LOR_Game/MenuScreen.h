#pragma once
#include "Screen.h"
class MenuScreen :
    public Screen
{
public:
    int virtual update() { return 0; };
    void virtual render() {};
    virtual void handleEvent(SDL_Event event) {};
};

