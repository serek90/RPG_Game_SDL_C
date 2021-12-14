#include "Guard.h"


void Guard::Move()
{
	static int counter = 0;

	if (counter <= 300)
		xIncrease();
	else if (counter == 600)
		counter = 0;
	else
		xDecrease();
	
	counter++;

	Update();
}