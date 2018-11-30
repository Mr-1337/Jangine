#include "ButtonBase.h"
#include "../Util/Logger.h"

namespace Jangine
{

	ButtonBase::ButtonBase(SDL_Renderer* renderer)
		:UIElement(renderer), m_mDown(false)
	{
		onClick = [] { Logger::LogError("HEY IDIOT THIS BUTTON ISN'T BOUND TO ANYTHING"); };
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

	ButtonBase::~ButtonBase()
	{
	}

}