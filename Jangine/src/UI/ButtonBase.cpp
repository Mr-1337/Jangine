#include "ButtonBase.h"
#include "../Util/Logger.h"

namespace Jangine
{

	ButtonBase::ButtonBase()
		:m_mDown(false)
	{
		onClick = [] { Logger::LogError("HEY IDIOT THIS BUTTON ISN'T BOUND TO ANYTHING!"); };
	}

	ButtonBase::~ButtonBase()
	{

	}

	bool ButtonBase::mouseInBounds()
	{
		SDL_Rect* sRect = m_sprite->getRect();
		if ((mX >= sRect->x) && (mX <= sRect->x + sRect->w) && (mY >= sRect->y) && (mY <= sRect->y + sRect->h))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void ButtonBase::update()
	{
		buttonMask = SDL_GetMouseState(&mX, &mY);

		if (buttonMask == SDL_BUTTON_LMASK)
		{
			if (!m_mDown && mouseInBounds())
			{
				onClick();
			}
			m_mDown = true;
		}
		else
		{
			m_mDown = false;
		}
	}
}