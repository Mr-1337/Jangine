#pragma once

#include <SDL.h>

namespace Globals
{
	void setWindow(SDL_Window* w);
	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();
}