#include "UIElement.h"
#include "../Core/Globals.h"

namespace Jangine
{

	UIElement::UIElement():
		m_renderer(SDL_GetRenderer(Globals::getWindow()))
	{
	}


	UIElement::~UIElement()
	{
	}


	void UIElement::setX(int X)
	{
		x = X;
		m_sprite->setX(x);
	}

	void UIElement::setY(int Y)
	{
		y = Y;
		m_sprite->setY(y);
	}

}