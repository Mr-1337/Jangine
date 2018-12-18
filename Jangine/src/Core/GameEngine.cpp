#include "GameEngine.h"
#include "Globals.h"
#include "../Util/Logger.h"
#include <string>
#include <sstream>

namespace Jangine
{
	GameEngine::GameEngine(std::string title)
		: setState_(false)
	{
		//Only let the application loop execute if window creation and renderer creation succeed

		int width, height;
		GameSettings::getDimensions(&width, &height);
		Logger::SetLogLevel(Logger::LEVEL_TRACE);

		if (initializeLibs())
		{
			//Window and rendering creation
			window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
			if (window_ == nullptr)
			{
				Logger::LogErrorSDL("Window creation failed!");
			}
			else
			{
				renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

				if (renderer_ == nullptr)
				{
					Logger::LogErrorSDL("Renderer creation failed!");
				}
				else
				{
					Globals::setWindow(window_);
					SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);
					stateMachine_ = std::make_unique<StateMachine>();
				}
			}
		}
		else
		{
			Logger::Log("Failed to load libraries needed to start engine.", Logger::LOG_ERROR, Logger::LEVEL_CRITICAL);
			Logger::Log("Maybe you are missing some of the SDL DLL files or the game didn't install correctly? Or maybe SDL itself is miffed, it happens.", Logger::LOG_ERROR, Logger::LEVEL_CRITICAL);
			throw std::runtime_error("Failed to load libraries. Do me a solid and report this!");
		}
	}

	GameEngine::~GameEngine()
	{
		Logger::Log("Destroying game engine", Logger::LOG_INFO, Logger::LEVEL_TRACE);
		SDL_DestroyRenderer(renderer_);
		SDL_DestroyWindow(window_);
		//Destroy the state machine before shutting down SDL. This is to prevent SDL calls from happening after shutdown.
		stateMachine_ = nullptr;
		shutdown();
	}

	void GameEngine::Run()
	{
		//Loop the program until the state machine requests to quit or the user closes the program
		//Update and draw based on current game state
		if (setState_)
		{
			while (stateMachine_->running())
			{
				stateMachine_->eventHandler();
				stateMachine_->update();
				stateMachine_->draw();
				stateMachine_->checkStateUpdate();
			}
		}
		else
		{
			throw std::runtime_error ("First state wasn't set! Please call SetFirstState before using Run!");
		}
	}

	void GameEngine::shutdown()
	{
		SDLNet_Quit();
		TTF_Quit();
		Mix_CloseAudio();
		Mix_Quit();
		IMG_Quit();
		SDL_Quit();
	}

	bool GameEngine::initializeLibs()
	{
		bool success = true;
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		{
			Logger::LogErrorSDL("SDL failed to launch! It's like needed for everything though :(");
			success = false;
		}
		else
		{
			SDL_version version;
			SDL_GetVersion(&version);

			std::stringstream link;
			std::stringstream compiled;

			link << "The program has linked against SDL version " << (int)version.major << "." << (int)version.minor << "." << (int)version.patch;
			SDL_VERSION(&version);
			compiled << "The program has compiled SDL version " << (int)version.major << "." << (int)version.minor << "." << (int)version.patch;

			Logger::Log(link.str(), Logger::LOG_INFO, Logger::LEVEL_TRACE);
			Logger::Log(compiled.str(), Logger::LOG_INFO, Logger::LEVEL_TRACE);

			int imgFlags = IMG_INIT_PNG;
			if (!((IMG_Init(imgFlags))&imgFlags))
			{
				Logger::LogErrorIMG("SDL_Image failed to launch!");
				success = false;
			}
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) != 0)
			{
				Logger::LogErrorMIX("SDL_Mixer failed to launch!");
				success = false;
				int sndFlags = MIX_INIT_MP3 | MIX_INIT_OGG;
				if ((Mix_Init(sndFlags)&sndFlags) != sndFlags)
				{
					Logger::LogErrorMIX("SDL_Mixer failed to launch!");
					success = false;
				}
			}
			if (TTF_Init() != 0)
			{
				Logger::LogErrorTTF("SDL_ttf failed to launch!");
				success = false;
			}
			if (SDLNet_Init() == -1)
			{
				Logger::LogErrorNET("SDL_Net failed to launch!");
				success = false;
			}
		}
		return success;
	}

}