#pragma once

#include <SDL.h>

namespace Jangine
{

	class IInputReceiver
	{
	public:
		IInputReceiver();
		virtual void ProcessInput(SDL_Event& e) = 0;
		~IInputReceiver();
	};

}

