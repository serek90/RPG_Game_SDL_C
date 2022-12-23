#include <iostream>
#include <gtest/gtest.h>

#include "../RPG_LOR_Game/MapScreen.h"
#include "../RPG_LOR_Game/GameOverScreen.h"
#include "../RPG_LOR_Game/MenuScreen.h"
#include "../RPG_LOR_Game/Hero.h"


/**********************************************
*MapScreenInit tests section
***********************************************/
struct MapScreenTest : testing::Test
{
	MapScreen* screen;
	MapScreenTest()
	{
		screen = new MapScreen;
	}

	~MapScreenTest()
	{
		delete screen;
	}
};

TEST_F(MapScreenTest, init)
{
	EXPECT_EQ(1, screen->isOn());
}

TEST(MapScreenInit, init)
{
	MapScreen screen;
	EXPECT_EQ (1, screen.isOn());
}

/**********************************************
*GameOverscreenInit tests section
***********************************************/
TEST(GameOverscreenInit, init)
{
	GameOverScreen screen;
	EXPECT_EQ(0, screen.isOn());
}

TEST(MenuScreenInit, init)
{
	MenuScreen screen;
	EXPECT_EQ(1, screen.isOn());
}

/**********************************************
*Hero classtests section
***********************************************/
struct HeroTest : testing::Test
{
	Hero* hero;
	HeroTest()
	{
		hero = new Hero("graphics/knight.png", 192, 192, 8);;
	}

	~HeroTest()
	{
		delete hero;
	}
};

TEST_F(HeroTest, show)
{
	EXPECT_EQ(1, hero->isShowing());
}

TEST_F(HeroTest, hide)
{
	hero->stopShowing();
	EXPECT_EQ(0, hero->isShowing());
}


int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
