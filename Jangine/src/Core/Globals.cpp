#include "Globals.h"

namespace Globals
{
	namespace
	{
		SDL_Window* window;
	}
	SDL_Window* getWindow()
	{
		return window;
	}
	void setWindow(SDL_Window* w)
	{
		window = w;
	}
}