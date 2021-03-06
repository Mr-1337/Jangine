#include "Text.h"

namespace Jangine
{

	Text::Text(std::string message)
		:m_string(message)
	{

	}


	Text::~Text()
	{
		std::cout << "Text Destroyed" << std::endl;
		TTF_CloseFont(font);
	}

	void Text::load(std::string path, int pntSize, SDL_Color fontColor)
	{
		this->fontColor = fontColor;
		font = TTF_OpenFont(path.c_str(), pntSize);
		tempSurface = TTF_RenderText_Blended(font, m_string.c_str(), fontColor);
		m_dstRect.w = tempSurface->w;
		m_dstRect.h = tempSurface->h;
		m_dstRect.x = 0;
		m_dstRect.y = 0;
		m_texture = std::make_shared<Texture>(tempSurface);
		SDL_FreeSurface(tempSurface);
	}


	void Text::draw()
	{
		SDL_RenderCopy(m_renderer, m_texture->GetRaw(), NULL, &m_dstRect);
	}


	void Text::updateText(std::string text)
	{
		m_string = text;
		tempSurface = TTF_RenderText_Blended(font, m_string.c_str(), fontColor);
		m_dstRect.w = tempSurface->w;
		m_dstRect.h = tempSurface->h;
		m_texture.reset(new Texture(tempSurface));
		SDL_FreeSurface(tempSurface);
	}

}