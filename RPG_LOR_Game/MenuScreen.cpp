#include "MenuScreen.h"


MenuScreen::MenuScreen()
{
	_texture = TextureManager::LoadTexture("graphics/menu_screen.png");
}
MenuScreen::~MenuScreen()
{
	SDL_DestroyTexture(_texture);
}

Screen* MenuScreen::procedNext()
{
	Screen* next = new MapScreen();
	return next;
}

void MenuScreen::render()
{
	_dst.x = 0;
	_dst.y = 0;
	_dst.w = 1200;
	_dst.h = 800;
	SDL_RenderCopy(Game::renderer, _texture, NULL, &_dst);
}

void MenuScreen::handleEvent(SDL_Event event)
{
	int mouseX, mouseY;

	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		std::cout << "Mouse click" << std::endl;
		SDL_GetMouseState(&mouseX, &mouseY);
		std::cout << "Mouse x = " << mouseX << std::endl;
		std::cout << "Mouse y = " << mouseY << std::endl;
		_isOn = false;
	}
}
