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
    Guard(const char* textureSheet, int X, int Y, int color) : GameObject(textureSheet, X, Y), name(color) {}
    virtual ~Guard();

private:
  int name;
};

