/*
*
* created by: serek90
*/
#include "Item.h"

Item::~Item()
{
	std::cout << "Item destructor call" << std::endl;

}

bool Item::isOn()
{
	return _visible;
}

void Item::hide()
{
	_visible = false;
}