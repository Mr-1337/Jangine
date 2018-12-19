#pragma once
#include <SDL.h>
#include "../Graphics/Sprite.h"
#include "../Input/IInputReceiver.h"


namespace Jangine
{
	//Represents a singular UI element
	class UIElement: public IInputReceiver
	{
	public:
		UIElement();
		virtual ~UIElement() = 0;

		virtual void draw() = 0;
		virtual void update() = 0;

		virtual void setX(int X);
		virtual void setY(int Y);
		//virtual void ProcessInput(SDL_Event& e) = 0;

	protected:
		SDL_Renderer* m_renderer;
		Sprite* m_sprite;
		int x, y;
	};

}