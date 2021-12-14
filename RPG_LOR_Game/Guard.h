#pragma once
#include "GameObject.h"

class Guard :
    public GameObject
{
public:
    void Move();
    Guard(const char* textureSheet, int X, int Y, int color) : GameObject(textureSheet, X, Y), name(color) {}
    ~Guard();

private:
    int name;
};

