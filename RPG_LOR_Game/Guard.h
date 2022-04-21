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
    Guard(const char* textureSheet, int X, int Y, int color) : GameObject(textureSheet, X, Y), _name(color) {}
    virtual ~Guard();

    int _defence = 10; //move to private
    int _attack = 10;  //move to private

private:
  int _name;
  Guard();
  int _counter = 0;

};

