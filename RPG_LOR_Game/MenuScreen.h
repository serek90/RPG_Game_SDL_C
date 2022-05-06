#pragma once
#include "Screen.h"
#include "MapScreen.h"
#include "Button.h"

class MenuScreen :
    public Screen
{
    SDL_Texture* _texture;
    SDL_Texture* _button_1;
    SDL_Texture* _button_2;
    SDL_Texture* _button_3;
    SDL_Texture* _button_4;
    SDL_Rect  src, _dst;

public:
    MenuScreen();
    ~MenuScreen();
    int virtual update() { return 0; };
    void virtual render();
    virtual void handleEvent(SDL_Event event);
    Screen* procedNext();
};

