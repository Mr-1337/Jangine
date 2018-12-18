#include "Globals.h"

namespace Globals
{
	namespace
	{
		SDL_Window* window_;
		SDL_Renderer* renderer_;
	}
	SDL_Window* getWindow()
	{
		return window_;
	}
	SDL_Renderer* getRenderer()
	{
		return renderer_;
	}
	void setWindow(SDL_Window* w)
	{
		window_ = w;
		renderer_ = SDL_GetRenderer(window_);
	}
}