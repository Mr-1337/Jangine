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
		GameState();
		virtual ~GameState();
		virtual void update() = 0;
		virtual void draw() = 0;
		virtual void revealed();
		virtual void eventHandler();
		inline bool wantsToQuit() { return m_quit; };

		std::shared_ptr<GameState> getNextState();

	protected:

		std::shared_ptr<GameState> m_nextState;
		bool m_quit;
		SDL_Event m_event;
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
	};

}