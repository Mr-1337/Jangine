#include "StateMachine.h"

namespace Jangine
{

	StateMachine::StateMachine() :
		m_running(true)
	{

	}

	StateMachine::~StateMachine()
	{
		std::cout << currentState.use_count() << " references to the current state" << std::endl;
		std::cout << "This is to check for circular references with shared_ptr. If this is more than 1, a state may not have been deallocated." << std::endl;
		std::cout << "Destroyed state machine" << std::endl;
	}

	void StateMachine::setState(std::shared_ptr<GameState> newState)
	{
		if (newState != nullptr)
		{
			currentState = newState;
		}
	}

	bool StateMachine::running()
	{
		return m_running;
	}

	void StateMachine::eventHandler()
	{
		currentState->eventHandler();
	}

	void StateMachine::draw()
	{
		currentState->draw();
	}

	void StateMachine::checkStateUpdate()
	{
		m_running = !currentState->wantsToQuit();
		setState(currentState->getNextState());
	}

	void StateMachine::update()
	{
		currentState->update();
	}

}