#pragma once

#include <SDL.h>
#include <iostream>
#include <SDL_mixer.h>
#include "../Core/Globals.h"
#include "../Core/Platform.h"
#include "../Util/Logger.h"


namespace Jangine
{
	/*
		A GameState is some mode that the game can be in. It is a way to allow radically different behavior within the same framework.
		You can define your own GameState by inheriting from this class. To switch states, assign the nextState pointer to a new GameState
		of your chosing. It can be contructed with parameters if need be.
	*/
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