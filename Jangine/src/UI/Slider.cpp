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
		int mx;

		if ((SDL_GetMouseState(&mx, nullptr) & SDL_BUTTON_LEFT) && mouseInBounds())
		{
			auto srcRect = m_sprite->getRect();
			if (mx > srcRect->x + srcRect->w - 10)
			{
				wedge.x = srcRect->x + srcRect->w - 10;
			}
			else if (mx < srcRect->x + 5)
			{
				wedge.x = srcRect->x;
			}
			else
			{
				wedge.x = mx - 5;
				int volume = static_cast<int>(static_cast<float>(wedge.x - this->x) / (srcRect->w - 20) * 128.0f);
				Logger::Log(std::to_string(volume));
				Mix_VolumeMusic(volume);
			}
		}
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