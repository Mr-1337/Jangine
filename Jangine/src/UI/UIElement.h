#pragma once
#include <SDL.h>
#include "../Graphics/Sprite.h"

//Represents a singular UI element

namespace Jangine
{

	class UIElement
	{
	public:
		UIElement();
		virtual ~UIElement() = 0;

		virtual void draw() = 0;
		virtual void update() = 0;

		virtual void setX(int X);
		virtual void setY(int Y);

	protected:
		SDL_Renderer* m_renderer;
		Sprite* m_sprite;
		int x, y;
	};

}