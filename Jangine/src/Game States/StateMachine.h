#pragma once

#include <stack>
#include <memory>
#include "GameState.h"
#include "../Core/Platform.h"
#include "../Util/Timer.h"


namespace Jangine
{
	//Houses all the different game states, facilitates their usage, and contains logic for switching
	class StateMachine
	{
	public:
		StateMachine();
		~StateMachine();
		void setState(std::shared_ptr<GameState> newState);
		void update();
		void draw();
		void eventHandler();
		bool running();
		void checkStateUpdate();

	private:
		std::shared_ptr<GameState> currentState;
		bool m_running;
		SDL_Window* m_window;
		Timer frameTime;
	};

}