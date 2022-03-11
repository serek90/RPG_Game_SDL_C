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

std::ostream& operator<<(std::ostream& os, const Item& item)
{
	os << item._name << std::endl;
	return os;
}