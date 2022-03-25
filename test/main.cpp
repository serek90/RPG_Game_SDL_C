#include <iostream>
#include <gtest/gtest.h>
//#include "../RPG_LOR_Game/Screen.h"
//#include "../RPG_LOR_Game/MapScreen.h"

class MapScreen
{
public:
	int isOn() { return 0; }
};


TEST(blaTest, test1)
{
	MapScreen screen;
	EXPECT_EQ (0, screen.isOn());
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
