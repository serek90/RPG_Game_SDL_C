#include "Guard.h"

Guard::~Guard()
{
	
}

void Guard::Move()
{
	static int counter = 0, slow = 0;

	if (slow++ == 10)
	{

		if (counter <= 300)
			xIncrease();
		else if (counter == 600)
			counter = 0;
		else
			xDecrease();

		counter++; 
		slow = 0;

	}

	Update();
}