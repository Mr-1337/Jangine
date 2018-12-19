#include "UIContainer.h"
#include "../Core/Globals.h"

namespace Jangine
{

	UIContainer::UIContainer()
		:m_renderer(Globals::getRenderer())
	{
	}


	UIContainer::~UIContainer()
	{
	}


	void UIContainer::add(std::shared_ptr<UIElement> child)
	{
		children.push_back(child);
	}

	void UIContainer::ProcessInput(SDL_Event& e)
	{
		for (auto& c : children)
		{
			c->ProcessInput(e);
		}
	}

	void UIContainer::update()
	{
		for (auto c : children)
		{
			c->update();
		}
	}


	void UIContainer::draw()
	{
		for (auto c : children)
		{
			c->draw();
		}
	}

}