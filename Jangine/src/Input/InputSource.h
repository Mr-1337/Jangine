#pragma once

#include <vector>
#include "IInputReceiver.h"

namespace Jangine
{

	class InputSource
	{
	public:

		//Creates a new input source. Specify the type of input source this is
		InputSource();
		~InputSource();

		void PumpEvents(SDL_Event& e);
		void Attach(IInputReceiver& subscriber);

	private:
		std::vector<IInputReceiver*> subscribers;
	};

}