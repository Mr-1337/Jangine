#include "UIElement.h"

namespace Jangine
{

	UIElement::UIElement(SDL_Renderer* renderer)
		:m_renderer(renderer)
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