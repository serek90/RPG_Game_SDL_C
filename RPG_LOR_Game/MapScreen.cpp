#include "MapScreen.h"
#include <iostream>

MapScreen::MapScreen()
{
	_player = new Hero("graphics/knight.png", 192, 192, 8);
	_enemy_1 = new Guard("graphics/guard_right.png", 0, 0, 0);
	_enemy_2 = new Guard("graphics/guard_right.png", 0, 96, 0);
	_sword = new Item("graphics/sword.png", 100, 296, "sword_1");
	_map = new Map();

}

int MapScreen::update()
{
	if (_enemy_1)_enemy_1->Move();
	if (_enemy_2)_enemy_2->Move();
	if (_enemy_1 && _enemy_2)
	{
		if (_player->Collision(_enemy_1) || _player->Collision(_enemy_2))
		{
			if (_player->_attack > _enemy_1->_attack || _player->_attack > _enemy_2->_attack)
			{
				delete _enemy_1;
				delete _enemy_2;
				_enemy_1 = nullptr;
				_enemy_2 = nullptr;
				std::cout << "Enemy was killed" << std::endl;
			}
			else
			{
				delete _map;
				delete _player;
				delete _enemy_1;
				delete _enemy_2;
				delete _sword;

				this->off();
				return 1;
			}

		}
	}
	if (_sword->isOn())
	{
		if (_player->Collision(_sword))
		{
			_player->takeItem(_sword);
		}
		_sword->Update();
	}

	return 0;
}

void MapScreen::render()
{
	_map->Draw();
	_player->Render();
	if (_enemy_1)_enemy_1->Render();
	if (_enemy_2)_enemy_2->Render();
	if (_sword->isOn())
	{
		_sword->Render();
	}
}

void MapScreen::handleEvent(SDL_Event event)
{
	_player->Move(event);
}

Screen* MapScreen::procedNext()
{
	Screen* next = new GameOverScreen();
	return next;
}