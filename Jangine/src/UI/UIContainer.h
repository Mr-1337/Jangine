#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include <iterator>
#include "../Input/IInputReceiver.h"
#include "UIElement.h"

namespace Jangine
{

	class UIContainer: public IInputReceiver
	{
	public:
		UIContainer();
		virtual ~UIContainer() = 0;

		virtual void update();
		virtual void draw();

		void add(std::shared_ptr<UIElement> child);
		void ProcessInput(SDL_Event& e) override;

	protected:
		SDL_Renderer* m_renderer;
		std::vector<std::shared_ptr<UIElement>> children;
		std::vector<std::shared_ptr<UIElement>>::iterator iter;
	};

}