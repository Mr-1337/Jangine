#pragma once
#include "../Graphics/Sprite.h"
#include "../Input/IInputReceiver.h"
#include "UIElement.h"
#include <functional>

namespace Jangine
{
	class ButtonBase
		:public UIElement, public IInputReceiver
	{
	public:
		ButtonBase();
		std::function<void()> onClick;
		virtual ~ButtonBase() = 0;

		virtual void update() override;
		virtual void ProcessInput(SDL_Event& e) override;

	protected:

		virtual void onHover() = 0;
		bool mouseInBounds(int mX, int mY);
		bool hover;

	};

}