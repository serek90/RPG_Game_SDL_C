#include "MenuScreen.h"
#include <chrono>
#include <thread>


MenuScreen::MenuScreen()
{
	_texture = TextureManager::LoadTexture("graphics/menu_screen.png");
	button = new Button("graphics/exit_button.png","graphics/exit_button_clicked.png", 10, 10, 200 , 200);

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
	button->render();

}

void MenuScreen::handleEvent(SDL_Event event)
{
	int mouseX, mouseY;
	static int ctr = 0;
	static bool clicked = false;

	if(clicked && ctr++ == 1000)
		_isOn = false;
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		std::cout << "Mouse click" << std::endl;
		SDL_GetMouseState(&mouseX, &mouseY);
		std::cout << "Mouse x = " << mouseX << std::endl;
		std::cout << "Mouse y = " << mouseY << std::endl;
		if (button->click_check(mouseX, mouseY))
		{
			clicked = true;
		}
	}
}
