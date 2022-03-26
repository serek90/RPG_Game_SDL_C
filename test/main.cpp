#include <iostream>
#include <gtest/gtest.h>

#include "../RPG_LOR_Game/MapScreen.h"
#include "../RPG_LOR_Game/GameOverScreen.h"
#include "../RPG_LOR_Game/MenuScreen.h"



TEST(MapScreenInit, init)
{
	MapScreen screen;
	EXPECT_EQ (1, screen.isOn());
}

TEST(GameOverscreenInit, init)
{
	GameOverScreen screen;
	EXPECT_EQ(1, screen.isOn());
}

TEST(MenuScreenInit, init)
{
	MenuScreen screen;
	EXPECT_EQ(1, screen.isOn());
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
