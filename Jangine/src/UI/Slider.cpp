#include "Slider.h"
#include "../Util/Logger.h"

namespace Jangine
{

	Slider::Slider()
	{
		m_sprite = new Sprite();
		m_sprite->load("Assets/Graphics/slider.png");
		wedge.w = 10;
		wedge.h = 60;
	}

	void Slider::onHover()
	{

	}

	void Slider::update()
	{
		
	}

	void Slider::draw()
	{
		m_sprite->draw();
		SDL_SetRenderDrawColor(m_renderer, 230, 120, 0, 255);
		SDL_RenderFillRect(m_renderer, &wedge);
	}

	void Slider::setY(int y)
	{
		UIElement::setY(y);
		wedge.y = y - 15;
	}

	void Slider::setX(int x)
	{
		UIElement::setX(x);
		wedge.x = x;
	}

	Slider::~Slider()
	{
		delete m_sprite;
	}

}