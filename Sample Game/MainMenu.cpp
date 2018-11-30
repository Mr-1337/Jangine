#include "MainMenu.h"
#include <Util/Logger.h>

MainMenu::MainMenu(const std::string& msg, int count) :
	sprite(m_renderer)
{
	for (int i = 0; i < count; i++)
	{
		Jangine::Logger::Log(msg);
	}
	sprite.load("rtx.png");
}


MainMenu::~MainMenu()
{
}


void MainMenu::update()
{
}


void MainMenu::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
	SDL_Rect r = { 0, 0, 60, 30 };
	SDL_RenderFillRect(m_renderer, &r);
	sprite.draw();
	SDL_RenderPresent(m_renderer);
}
