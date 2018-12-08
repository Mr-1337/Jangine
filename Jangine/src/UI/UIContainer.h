#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include <iterator>
#include "UIElement.h"

namespace Jangine
{

	class UIContainer
	{
	public:
		UIContainer();
		virtual ~UIContainer() = 0;

		virtual void update();
		virtual void draw();

		void add(std::shared_ptr<UIElement> child);

	protected:
		SDL_Renderer* m_renderer;
		std::vector<std::shared_ptr<UIElement>> children;
		std::vector<std::shared_ptr<UIElement>>::iterator iter;
	};

}