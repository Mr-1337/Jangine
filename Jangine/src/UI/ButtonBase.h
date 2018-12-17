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
		ButtonBase();
		std::function<void()> onClick;
		virtual ~ButtonBase() = 0;

		virtual void update() override;

	protected:

		virtual void onHover() = 0;
		bool mouseInBounds();
		int buttonMask;
		int mX;
		int mY;

		bool m_mDown;

	};

}