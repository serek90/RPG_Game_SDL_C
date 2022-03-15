#pragma once
#include "Screen.h"
#include "Map.h"
#include "Hero.h"
#include "Guard.h"
#include "Hero.h"

class MapScreen :
    public Screen
{
private:
    Hero* _player;
    Guard* _enemy_1, * _enemy_2;
    Item* _sword;
    Map* _map;
public:
    MapScreen();
    virtual ~MapScreen() { };

    int virtual update();
    void virtual render();
    virtual void handleEvent(SDL_Event event);
};

