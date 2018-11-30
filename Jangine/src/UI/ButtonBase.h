#pragma once
#include "../Graphics/Sprite.h"
#include "UIElement.h"
#include <functional>

namespace Jangine
{
	class ButtonBase
		:public UIElement
	{
	public:
		ButtonBase(SDL_Renderer* renderer);
		std::function<void()> onClick;
		virtual ~ButtonBase() = 0;

	protected:

		virtual void onHover() = 0;
		bool mouseInBounds();
		int mX;
		int mY;

		bool m_mDown;

	};

}