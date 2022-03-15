#pragma once
#include "Screen.h"
class MenuScreen :
    public Screen
{
public:
    int virtual update() {};
    void virtual render() {};
    virtual void handleEvent(SDL_Event event) {};
};

