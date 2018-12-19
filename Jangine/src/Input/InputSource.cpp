#include "InputSource.h"

namespace Jangine
{
	InputSource::InputSource()
	{

	}

	InputSource::~InputSource()
	{

	}

	void InputSource::Attach(IInputReceiver& subscriber)
	{
		subscribers.push_back(&subscriber);
	}

	void InputSource::PumpEvents(SDL_Event& e)
	{
		for (auto& s : subscribers)
		{
			s->ProcessInput(e);
		}
	}
}