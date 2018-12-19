#include "ButtonBase.h"
#include "../Util/Logger.h"

namespace Jangine
{

	ButtonBase::ButtonBase() :
		hover(false)
	{
		onClick = [] { Logger::LogError("HEY IDIOT THIS BUTTON ISN'T BOUND TO ANYTHING!"); };
	}

	ButtonBase::~ButtonBase()
	{

	}

	bool ButtonBase::mouseInBounds(int mX, int mY)
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

	void ButtonBase::ProcessInput(SDL_Event& e)
	{
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			if (e.button.button == SDL_BUTTON_LEFT)
			{
				if (mouseInBounds(e.button.x, e.button.y))
				{
					onClick();
				}
			}
			
		}
		else if (e.type == SDL_MOUSEMOTION)
		{
			if (mouseInBounds(e.motion.x, e.motion.y))
				hover = true;
			else
				hover = false;
		}
	}

	void ButtonBase::update()
	{
		if (hover)
			onHover();
	}
}