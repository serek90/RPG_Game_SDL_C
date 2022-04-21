/*
*
* created by: serek90
*/
#include "Guard.h"

Guard::~Guard()
{
	
}

void Guard::Move()
{
	static  int slow = 0;

	if (slow++ == 10)
	{

		if (_counter < 300)
			xIncrease();
		else if (_counter == 600)
		{
			_counter = 0;
			this->updateTexture("graphics/guard_right.png");
		}
		else if (_counter == 300)
		{
			this->updateTexture("graphics/guard_left.png");
		}
		else
			xDecrease();

		_counter++; 
		slow = 0;
	}

	Update();
}