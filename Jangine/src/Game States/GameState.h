#pragma once

#include <SDL.h>
#include <iostream>
#include <SDL_mixer.h>
#include "../Core/Globals.h"
#include "../Core/Platform.h"
#include "../Util/Logger.h"

//Abstract type for different GameStates

namespace Jangine
{

	class GameState :
		public std::enable_shared_from_this<GameState>
	{
	public:
		JAN_API GameState();
		JAN_API virtual ~GameState();
		JAN_API virtual void update() = 0;
		JAN_API virtual void draw() = 0;
		JAN_API virtual void revealed();
		JAN_API virtual void eventHandler();
		JAN_API inline bool wantsToQuit() { return m_quit; };

		std::shared_ptr<GameState> getNextState();

	protected:

		std::shared_ptr<GameState> m_nextState;
		bool m_quit;
		SDL_Event m_event;
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
	};

}