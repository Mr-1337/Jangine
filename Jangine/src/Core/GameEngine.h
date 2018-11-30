#pragma once
//Contains core facilities for the game engine

#include "Platform.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <iostream>
#include "../Game States/StateMachine.h"
#include "GameSettings.h"

namespace Jangine
{

	class GameEngine
	{
	public:
		JAN_API GameEngine(std::string title);
		JAN_API virtual ~GameEngine();
		JAN_API void Run();

		template <class firstState, class... Ts>
		void SetFirstState(Ts... ts)
		{
			stateMachine_->setState(std::move(std::make_unique<firstState>(ts...)));
			setState_ = true;
		}

	private:

		//Load through each component and terminate if any fail
		bool initializeLibs();
		//Shut down SDL + extensions
		void shutdown();

		bool setState_;
		SDL_Renderer* renderer_;
		SDL_Window* window_;
		std::unique_ptr<StateMachine> stateMachine_;

	};

}