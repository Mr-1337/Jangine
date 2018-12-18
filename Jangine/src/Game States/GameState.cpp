#include "GameState.h"

namespace Jangine
{

	GameState::GameState()
		: m_window(Globals::getWindow()), m_renderer(Globals::getRenderer()), m_quit(false)
	{
		if (m_renderer == nullptr)
			Logger::LogError("Renderer was null!");
	}

	GameState::~GameState()
	{
	}

	void GameState::eventHandler()
	{
		while (SDL_PollEvent(&m_event) != 0)
		{
			switch (m_event.type)
			{
			case SDL_QUIT:
				m_quit = true;
			}
		}
	}

	void GameState::revealed()
	{
		m_nextState = nullptr;
	}

	std::shared_ptr<GameState> GameState::getNextState()
	{
		return m_nextState;
	}

}