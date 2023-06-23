#pragma once
#include "Screen.h"
#include "MapScreen.h"
#include "Button.h"

class MenuScreen :
    public Screen
{
    SDL_Texture* _texture;


    SDL_Rect  src, _dst;
    Button* button;

public:
    MenuScreen();
    ~MenuScreen();
    int virtual update() { return 0; };
    void virtual render();
    virtual void handleEvent(SDL_Event event);
    Screen* procedNext();
};

