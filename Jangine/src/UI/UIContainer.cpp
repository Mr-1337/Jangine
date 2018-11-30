#include "UIContainer.h"

namespace Jangine
{

	UIContainer::UIContainer(SDL_Renderer* renderer)
		:m_renderer(renderer)
	{
	}


	UIContainer::~UIContainer()
	{
	}


	void UIContainer::add(std::shared_ptr<UIElement> child)
	{
		children.push_back(child);
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