/*
*
* created by: serek90
*/
#pragma once
#include "GameObject.h"
#include <iostream>

class Guard :
    public GameObject
{
public:
    void Move();
    Guard(const char* textureSheet, int X, int Y, int color) : GameObject(textureSheet, X, Y), _name(color) {
        _defence = 10;
        _attack = 10;
    }
    virtual ~Guard();

private:
  int _name;
  Guard();
  int _counter = 0;

};

